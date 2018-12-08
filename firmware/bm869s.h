// Credit to user 'jesuscf' of the EEVBlog Forum.
// The meaning of each of the bytes received from the multimeter
// Byte 0
#define AUTO 0x01
#define R    0x02
#define C    0x04
#define H    0x08
#define DC   0x10
#define MAX  0x20
#define MIN  0x40
#define AVG  0x80
// Byte 1
#define AC_1         0x01
#define T1           0x02
#define temp_minus   0x04
#define T2_1         0x08
#define bar_scale    0x10
#define bar_negative 0x20
#define VFD          0x40
#define negative_1   0x80
// Segments for all digits
#define seg_p 0x01 // Usually the dot of the previous number
#define seg_e 0x02
#define seg_f 0x04
#define seg_a 0x08
#define seg_d 0x10
#define seg_c 0x20
#define seg_g 0x40
#define seg_b 0x80
// Byte 2: 7-SEG 1
#define DELTA  0x01
// Byte 3: 7-SEG 2
// Byte 4: 7-SEG 3
// Byte 5: 7-SEG 4
// Byte 6: 7-SEG 5
// Byte 7: 7-SEG 5
#define V_1 0x01
// Byte 8
#define u_2        0x01 // u as in micro
#define m_2        0x02 // m as in milli
#define A_2        0x04
#define ma20       0x08
#define negative_2 0x10
#define AC_2       0x20
#define T2_2       0x40
#define battery    0x80
// Byte 9: 7-SEG 7
#define sound 0x01
// Byte 10: 7-SEG 8
// Byte 11: 7-SEG 8
// Byte 12: 7-SEG 8
// Byte 13
#define M_2   0x01
#define k_2   0x02
#define Hz_2  0x04
#define V_2   0x08
#define S     0x10
#define FARAD 0x20
#define n     0x40
#define A_1   0x80
// Byte 14
#define Hz_1 0x01
#define dB   0x02
#define m_1  0x04
#define u_1  0x08
#define OHM  0x10
#define M_1  0x20
#define k_1  0x40
#define DUTY 0x80

// The codes for some of letters and the numbers
#define LETTER_C 0x1e
#define LETTER_d 0xf2
#define LETTER_F 0x4e
#define LETTER_i 0x20
#define LETTER_L 0x16
#define LETTER_o 0x72
#define BLANK    0x00
#define DASH     0x40
#define NUMBER_0 0xbe
#define NUMBER_1 0xa0
#define NUMBER_2 0xda
#define NUMBER_3 0xf8
#define NUMBER_4 0xe4
#define NUMBER_5 0x7c
#define NUMBER_6 0x7e
#define NUMBER_7 0xa8
#define NUMBER_8 0xfe
#define NUMBER_9 0xfc
