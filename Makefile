# #######################################################################
# Makefile for inclusion by other projects
#   heavily copied from original libarduino sources
#   (c) 2009, for all changes belong to Henrik Sandklef
#	which lead to the current version
#	(c) 2011, for all changes belong to Petre Mihail Anton
#######################################################################

#     Change device names to corespond to your system
#  Description
#  =============
#    DUE_USB_DEV - used for Arduino DueMillaNove
#    UNO_USB_DEV - used for Arduino Uno
#
# here are various USB device names for various operating system and Arduinos:
# if you're using GNU/Linux (Ubuntu/Debian/Fedora.....):
#	DUE_USB_DEV=/dev/ttyUSB0
#	UNO_USB_DEV=/dev/ttyACM0
# if you're using Mac:
#	DUE_USB_DEV=
#	UNO_USB_DEV=/dev/tty.usbmodemfa141 (check name!)
# Hint:
#    Launch the Arduino program to see what your USB device 
#    is called (look under the port settings)
                                                                                  
USB_PORT=/dev/ttyACM0

#########################################################################
#########################################################################
#########################################################################

# the speed that corresponds to your arduino (normally 16MHz)
F_CPU=16000000
#F_CPU=8000000
		
LDFLAGS=-Wl,-Map=$(PROG).map,--cref -mmcu=$(MMCU) -Iinclude -lm -Llib -l$(LIB)
AVRDUDE = avrdude -p $(MMCU) -P $(USB_PORT) -c $(STK) -b $(BAUD) -F -u -U flash:w:$(PROG).rom

PROG=main
SRC=src/*.c
OBJ=bin/*.o

#	echo '#include "WProgram.h"' > $(TARGET).c
#	cat $(PROG).c >> $(TARGET).c

$(OBJ): $(SRC)
	cd bin && \
	avr-gcc -c -g -Os -ffunction-sections -fdata-sections -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -Wall -Wstrict-prototypes -Wa,-ahlms=$(PROG).lst -fno-exceptions -I../include ../$(SRC)

#-DENABLE_PWM
#-DARDUINO=22

$(PROG): MMCU=atmega328p
		STK=stk500v1
		BAUD=57600
		LIB=coreuno.a
$(PROG): $(OBJ)
	avr-gcc $(OBJ) lib/lib$(LIB) $(LDFLAGS) -o bin/$(PROG).x
	@ echo "Test passed"

install: $(OBJ)
	avr-gcc $(OBJ) lib/$(LIB) $(LDFLAGS) -o $(PROG).elf
	avr-objcopy -O srec $(PROG).elf $(PROG).rom
	checksize $(PROG).elf
	$(AVRDUDE)

mega: MMCU=atmega2560
		STK=stk500v2
		BAUD=115200
		LIB=libcoremega.a
mega: install

uno: MMCU=atmega328p
		STK=stk500v1
		BAUD=57600
		LIB=coreuno.a
uno: install

due: MMCU=atmega328p
		STK=stk500v1
		BAUD=57600
		LIB=coreuno.a
due: install

pc:
	gcc -DPC $(SRC) -o bin/$(PROG)

clean:
	@ cd bin && rm -f *.o *.rom *.elf *.map *~ *.lst *.x
	@ echo "Project cleaned"
	
help:
	@ echo "Check your code includes 'WProgram.h' \nCheck you call 'init()'"

# reprogram the fuses for the right clock source
#fuse:
#	avrdude -p atmega168 -c stk200 -U lfuse:w:0x62:m
	
.PHONY : clean uno due mega install help
