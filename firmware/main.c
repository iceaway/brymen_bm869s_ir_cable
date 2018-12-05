#include <avr/io.h>
#include <util/delay.h>

#include <bm869s.h>
#include <avr305.h>

#define HIGH 1
#define LOW 0
#define IRTX PB3
#define IRRX PB2

// Storage for the information received from the multimeter
#define BM_PBYTES 20 // 16 bytes with data and 4 bytes with other information
unsigned char bm[BM_PBYTES];

void digitalWrite( int pin, int state )
{
    if ( state == HIGH ) {
        PORTB |= ( 1 << pin );
    } else {
        PORTB &= ~( 1 << pin );
    }
}

unsigned char digitalRead( int pin )
{
    return ( PINB & ( 1 << pin ) );
}

// Reads a byte from the multimeter
unsigned char getByte( void )
{
    unsigned char result, mask;

    // bit by bit check (using shift mask)
    // clock --> check --> "unclock"
    for ( mask = 1, result = 0; mask != 0; mask <<= 1 ) {
        digitalWrite( IRTX, HIGH );
        _delay_us( 250 );

        // checking on low instead of high, so maybe we can reuse
        // some work done on eevblog forum
        if ( digitalRead( IRRX ) == LOW ) result |= mask;

        digitalWrite( IRTX, LOW );
        _delay_us( 250 );
    }

    return result;
}

// Reads 20 bytes from the multimeter
int readBM689s ( void )
{
    unsigned int timeout;
    unsigned char j;

    // wait in case dmm is transmitting already
    while ( digitalRead( IRRX ) == HIGH );

    // init communication 10ms pulse
    digitalWrite( IRTX, HIGH );
    _delay_ms( 10 );
    digitalWrite( IRTX, LOW );
    timeout = 0;

    // wait for dmm response
    while ( digitalRead( IRRX ) == LOW ) {
        _delay_ms( 1 );
        timeout++;

        if ( timeout > 1000 ) break;
    }

    // if we did not reach timeout, get 20 bytes.
    if ( timeout <= 1000 ) {
        for ( j = 0; j < BM_PBYTES; j++ ) bm[j] = getByte();

        return 1;
    }

    return 0;
}

// Converts the digits information received into ASCII characters
char Decode_7seg ( unsigned char val )
{
    switch ( val & 0xfe ) {
        case LETTER_C: return'C'; break;

        case LETTER_d: return'd'; break;

        case LETTER_F: return'F'; break;

        case LETTER_i: return'i'; break;

        case LETTER_L: return'L'; break;

        case LETTER_o: return'o'; break;

        case BLANK:    return' '; break;

        case DASH:     return'-'; break;

        case NUMBER_0: return'0'; break;

        case NUMBER_1: return'1'; break;

        case NUMBER_2: return'2'; break;

        case NUMBER_3: return'3'; break;

        case NUMBER_4: return'4'; break;

        case NUMBER_5: return'5'; break;

        case NUMBER_6: return'6'; break;

        case NUMBER_7: return'7'; break;

        case NUMBER_8: return'8'; break;

        case NUMBER_9: return'9'; break;

        default:
            return'?';
            break;
    }
}

// Sends via serial port whatever was read and decoded from the multimeter for the main display
void Send_Disp1 ( void )
{
    char c;

    if ( ( ( bm[14] & Hz_1 ) == 0 ) && ( ( bm[14] & DUTY ) == 0 )
            && ( ( bm[14] & OHM ) == 0 ) && ( ( bm[13] & FARAD ) == 0 ) ) {
        printc( bm[1]&negative_1 ? '-' : '+' );
    }

    printc( Decode_7seg( bm[2] ) );

    if ( bm[3] & seg_p ) printc( '.' );

    printc( Decode_7seg( bm[3] ) );

    if ( bm[4] & seg_p ) printc( '.' );

    printc( Decode_7seg( bm[4] ) );

    if ( bm[5] & seg_p ) printc( '.' );

    printc( Decode_7seg( bm[5] ) );

    if ( bm[6] & seg_p ) printc( '.' );

    printc( Decode_7seg( bm[6] ) );
    c = Decode_7seg( bm[7] );

    if ( c != ' ' ) printc( c );

    // Display the units of voltage or current
    if ( ( bm[7] & V_1 ) || ( bm[13] & A_1 ) ) {
        if ( ( bm[14] & m_1 ) || ( bm[14] & u_1 ) ) {
            printc( 'E' );
            printc( '-' );
            printc( ( bm[14] & m_1 ) ? '3' : '6' );
        }

        printc( ' ' );

        if ( bm[7] & V_1 )
            printc( 'V' );
        else
            printc( 'A' );

        if ( bm[0] & DC ) {
            if ( bm[1] & AC_1 ) {
                printc( 'R' );
                printc( 'M' );
                printc( 'S' );
            } else {
                printc( 'D' );
                printc( 'C' );
            }
        } else if ( bm[1] & AC_1 ) {
            printc( 'A' );
            printc( 'C' );
        }
    }

    // Frequency
    if ( bm[14] & Hz_1 ) {
        if ( ( bm[14] & k_1 ) || ( bm[14] & M_1 ) ) {
            printc( 'E' );
            printc( '+' );

            if ( bm[14] & k_1 )
                printc( '3' );
            else
                printc( '6' );
        }

        printc( ' ' );
        printc( 'H' );
        printc( 'z' );
    }

    // Duty cycle
    if ( bm[14] & DUTY ) {
        printc( ' ' );
        printc( 'D' );
        printc( '%' );
    }

    // dB
    if ( bm[14] & dB ) {
        printc( ' ' );
        printc( 'd' );
        printc( 'B' );

        if ( bm[14] & m_1 ) printc( 'm' );
    }

    // Resistance
    if ( bm[14] & OHM ) {
        if ( ( bm[14] & k_1 ) || ( bm[14] & M_1 ) ) {
            printc( 'E' );
            printc( '+' );

            if ( bm[14] & k_1 )
                printc( '3' );
            else
                printc( '6' );
        }

        printc( ' ' );
        printc( 'O' );
        printc( 'H' );
        printc( 'M' );
    }

    // Capacitance
    if ( bm[13] & FARAD ) {
        if ( ( bm[13] & n ) || ( bm[14] & u_1 ) || ( bm[14] & m_1 ) ) {
            printc( 'E' );
            printc( '-' );

            if ( bm[13] & n )        printc( '9' );
            else if ( bm[14] & u_1 ) printc( '6' );
            else if ( bm[14] & m_1 ) printc( '3' );
        }

        printc( ' ' );
        printc( 'F' );
    }
}

// Sends via serial port whatever was read and decoded from the multimeter for the second display
void Send_Disp2 ( void )
{
    char c;
    c = Decode_7seg( bm[9] );

    if ( c != ' ' ) {
        printc( bm[8]&negative_2 ? '-' : '+' );
        printc( Decode_7seg( bm[9] ) );

        if ( bm[10] & seg_p ) printc( '.' );

        printc( Decode_7seg( bm[10] ) );

        if ( bm[11] & seg_p ) printc( '.' );

        printc( Decode_7seg( bm[11] ) );

        if ( bm[12] & seg_p ) printc( '.' );

        printc( Decode_7seg( bm[12] ) );

        // Display the units of voltage or current
        if ( ( bm[13] & V_2 ) || ( bm[8] & A_2 ) ) {
            if ( ( bm[8] & m_2 ) || ( bm[8] & u_2 ) ) {
                printc( 'E' );
                printc( '-' );
                printc( ( bm[8] & m_2 ) ? '3' : '6' );
            }

            printc( ' ' );

            if ( bm[13] & V_2 )
                printc( 'V' );
            else
                printc( 'A' );

            if ( bm[8] & AC_2 ) {
                printc( 'A' );
                printc( 'C' );
            } else {
                printc( 'D' );
                printc( 'C' );
            }
        }

        // Frequency
        if ( bm[13] & Hz_2 ) {
            if ( ( bm[13] & k_2 ) || ( bm[13] & M_2 ) ) {
                printc( 'E' );
                printc( '+' );

                if ( bm[13] & k_2 )
                    printc( '3' );
                else
                    printc( '6' );
            }

            printc( ' ' );
            printc( 'H' );
            printc( 'z' );
        }
    }
}

int main( void )
{
    // Pin initialization
    DDRB |= ( 1 << IRTX );       // port output
    DDRB &= ~( 1 << IRRX );      // port input
    PORTB &= ~( 1 << IRTX );     // set output ports to low

    while ( 1 ) {
        readBM689s();
        Send_Disp1();
        printc( ' ' );
        Send_Disp2();
        printc( '\r' );
        printc( '\n' );
        _delay_ms( 200 );
    }

    return 0;
}
