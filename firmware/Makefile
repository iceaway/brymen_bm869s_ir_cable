MCU =		attiny84a
MCU_AVRDUDE =		t84
AVR_TYPE =	__AVR_ATtiny84A__
F_CPU =		8000000UL
BAUD =		9600UL

#LIBDIR = ${HOME}/src/electronics/avr_libs
LIBDIR = 

PROGRAMMER_TYPE = usbtiny
PROGRAMMER_ARGS = 

### Program Locations

CC =		avr-gcc
OBJCOPY =	avr-objcopy
OBJDUMP =	avr-objdump
AVRSIZE =	avr-size
AVRDUDE =	avrdude

###------------------------------------------------------###
###                   Makefile Magic!                    ###
###         Summary:                                     ###
###             We want a .hex file                      ###
###        Compile source files into .elf                ###
###        Convert .elf file into .hex                   ###
###        You shouldn't need to edit below.             ###
###------------------------------------------------------###

## The name of your project (without the .c)
TARGET = main
## Or name it automatically after the enclosing directory
# TARGET = $(lastword $(subst /, ,$(CURDIR)))

# Object files: will find all .c/.h files in current directory
#  and in LIBDIR.  If you have any other (sub-)directories with code,
#  you can add them in to SOURCES below in the wildcard statement.
SOURCES=$(wildcard *.c $(LIBDIR)/*.c $(CURDIR)/lib/*.c)
OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(SOURCES:.c=.h)

## Compilation options, type man avr-gcc if you're curious.
CPPFLAGS = -DF_CPU=$(F_CPU) -DBAUD=$(BAUD) -D$(AVR_TYPE) -I. -I$(LIBDIR)
CFLAGS = -Os -g -std=gnu99 -Wall
## Use short (8-bit) data types 
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums 
## Splits up object files per function
CFLAGS += -ffunction-sections -fdata-sections 
LDFLAGS = -Wl,-Map,$(TARGET).map 
## Optional, but often ends up with smaller code
LDFLAGS += -Wl,--gc-sections 
## Relax shrinks code even more, but makes disassembly messy
# LDFLAGS += -Wl,--relax
# LDFLAGS += -Wl,-u,vfprintf -lprintf_flt -lm  ## for floating-point printf
# LDFLAGS += -Wl,-u,vfprintf -lprintf_min      ## for smaller printf
TARGET_ARCH = -mmcu=$(MCU)

## Explicit pattern rules:
##  To make .o files from .c files 
%.o: %.c $(HEADERS) Makefile
	 $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $<;

$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

%.hex: %.elf
	 $(OBJCOPY) -j .text -j .data -O ihex $< $@

%.eeprom: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@ 

%.lst: %.elf
	$(OBJDUMP) -S $< > $@

## These targets don't have files named after them
.PHONY: all debug size clean squeaky_clean flash flash_eeprom \
	avrdude_terminal fuses show_fuses

all: $(TARGET).hex 

debug:
	@echo
	@echo "Source files:"   $(SOURCES)
	@echo "MCU, F_CPU, BAUD:"  $(MCU), $(F_CPU), $(BAUD)
	@echo	

# Optionally show how big the resulting program is 
size:  $(TARGET).elf
	$(AVRSIZE) -C --mcu=$(MCU) $(TARGET).elf

clean:
	rm -f $(TARGET).elf $(TARGET).hex $(TARGET).obj \
	$(TARGET).o $(TARGET).d $(TARGET).eep $(TARGET).lst \
	$(TARGET).lss $(TARGET).sym $(TARGET).map $(TARGET)~ \
	$(TARGET).eeprom

squeaky_clean:
	rm -f *.elf *.hex *.obj *.o *.d *.eep *.lst *.lss *.sym *.map *~ *.eeprom

### Flashing code to AVR using avrdude

flash: $(TARGET).hex 
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU_AVRDUDE) $(PROGRAMMER_ARGS) -U flash:w:$<

flash_eeprom: $(TARGET).eeprom
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU_AVRDUDE) $(PROGRAMMER_ARGS) -U eeprom:w:$<

avrdude_terminal:
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU_AVRDUDE) $(PROGRAMMER_ARGS) -nt


### Fuse settings

# 8Mhz internal / preserve EEPROM / programming enabled
# see http://www.engbedded.com/fusecalc
LFUSE = 0xe2
HFUSE = 0xd7
EFUSE = 0xff

## Generic 
FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m 

fuses: 
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU_AVRDUDE) \
	           $(PROGRAMMER_ARGS) $(FUSE_STRING)
show_fuses:
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU_AVRDUDE) $(PROGRAMMER_ARGS) -nv	
