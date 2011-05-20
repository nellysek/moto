# #####################################################################
# Authors: Kristofer Hansson Aspman, Björn Eriksson, Magnus Bergqvist
#          and of course the creators of the original file, mentioned
#          below.
#
# #####################################################################
# This makefile has been modified from the original version to better
# suit the motor control group. Please see below for copyright information
# 
# Changes include rules for:
# - default (just gives a nice printout with instructions)
#   (Kristofer Hansson Aspman)
# - pc-dbg (Kristofer Hansson Aspman)
# - valgrind (Kristofer Hansson Aspman)
# - gcov (...coverage) also includes LCov! (Kristofer Hansson Aspman)
# - test and unit (CUnit master test suite) (Kristofer Hansson Aspman
#   and Björn Eriksson)
#
# In addition to this the following rules have been altered by
# Kristofer Hansson Aspman, Björn Eriksson and Magnus Bergqvist:
# - mega
# - pc
# #####################################################################
#
#   Original description and copyright follow:
#
# #####################################################################
#   Makefile for inclusion by other projects
#   heavily copied from original libarduino sources
#   (c) 2009, for all changes belong to Henrik Sandklef
#	which lead to the current version
#	(c) 2011, for all changes belong to Petre Mihail Anton
#######################################################################

#     Change device names to corespond to your system
#
# here are various USB device names for various operating system and Arduinos:
# if you're using GNU/Linux (Ubuntu/Debian/Fedora.....):
#	UUSB_PORT=/dev/ttyACM0
# if you're using Mac:
#	USB_PORT=/dev/tty.usbmodemfa141 (check name!)
# Hint:
#    Launch the Arduino program to see what your USB device 
#    is called (look under the port settings)


USB_PORT=/dev/ttyACM0
#USB_PORT=/dev/tty.usbmodem411

#########################################################################
#########################################################################
#########################################################################

# the speed that corresponds to your arduino (normally 16MHz)
F_CPU=16000000
#F_CPU=8000000

VERS="Arduino Portable Makefile [APM] version 1.2, dated 10-04-2011. Last updated 18-05-2011 by Kristofer Hansson Aspman"

### Additions/alterations made by Kristofer, Magnus, Björn
#########################################################################

PROG=test
TESTNAME=test_suite
SRC=src/*.c
SRC2=include/*.cpp
PROTO_SRC=../proto_mega/src/*.c
CUNIT_SRC=test/*.c

OBJ=bin/*.o
#########################################################################

### Additions/alterations made by Kristofer
#########################################################################
TESTSUITE_OBJ=bin/$(TESTNAME).o
FILES_TO_REMOVE=*.o *.rom *.elf *.map *~ *.lst *.o ../src/*.gcov \
	../../proto_mega/bin/*.o ../../../mov/bin/*.o \
	../../../ca/bin/*.o ../../main.o ../*.gcov ../*.gcno ../*.gcda \
	../src/*.o ../test/*.gcov ../test/*.gcda ../test/*.gcno ../test/test_suite.* \
	../test/..*c.gcov
PC_FLAGS=-DPC

default:
	@echo " "
	@echo "--- Normal compilation ----------------------------------"
	@echo "make pc     produces binary in bin/"
	@echo "make mega   produces binary for the Arduino and uploads"
	@echo "            to the board"
	@echo " "
	@echo "--- Cleaning up -----------------------------------------"
	@echo "make clean    recursively clean up subdirs"
	@echo " "
	@echo "--- Verification and debugging --------------------------"
	@echo "make pc-dbg       produces debug modebinary in bin/"
	@echo "make test         compiles unit tests"
	@echo "make unit         compiles and runs unit tests"
	@echo "make gcov         run unit tests with gcov (statement coverage)"
	@echo "make gcov2        run unit tests with gcov (branch coverage)"
	@echo "                  need to have LCov 1.9 installed!"
	@echo "make valgrind     run unit tests with valgrind"
	@echo " "

#########################################################################

mega: MMCU=atmega2560
mega: STK=stk500v2
mega: BAUD=115200
mega: LIB=coremega
mega: EXT=elf

uno: MMCU=atmega328p
uno: STK=stk500v1
uno: BAUD=115200
uno: LIB=coreuno
uno: EXT=elf

# I guess we have messed a bit with this one as well. Kristofer,
# Magnus and Björn
$(OBJ): $(SRC)
	@ cd bin && \
	avr-g++ -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -mmcu=$(MMCU) -DF_CPU=$(F_CPU) -DARDUINO -I../../include ../$(SRC) ../$(SRC2) ../$(PROTO_SRC)
	@ echo "Object files created"

compile:
	@ avr-gcc $(OBJ) -Os -Wl,--gc-sections -mmcu=$(MMCU) -o bin/$(PROG).$(EXT) -l$(LIB) -Llib -lm
	@ echo "Project compiled"

#-DENABLE_PWM
# avr-gcc $(OBJ) -Os -Wl,-Map=$(PROG).map,--cref -mmcu=$(MMCU) -DARDUINO=22 -l$(LIB) -Llib -lm \
#		-fno-exceptions  -ffunction-sections -fdata-sections -o bin/$(PROG).x

# Additions/Alterations by Kristofer Hansson Aspman
#########################################################################
test: PC_FLAGS+= -DMASTER_TEST_SUITE -DAUTOMATED
test: clean
	gcc $(PC_FLAGS) $(CUNIT_SRC) $(SRC) $(PROTO_SRC) -o bin/$(TESTNAME).o -lcunit

unit: test
	$(TESTSUITE_OBJ)
#########################################################################

install: $(OBJ) compile
	@ cd bin && avr-objcopy -O srec $(PROG).elf $(PROG).rom
#	checksize $(PROG).elf
	@ avrdude -p $(MMCU) -P $(USB_PORT) -c $(STK) -b $(BAUD) -F -u -U flash:w:bin/$(PROG).rom

mega: clean install

uno: clean install

pc: clean
	gcc -DPC $(SRC) $(PROTO_SRC) -o bin/$(PROG).o

# Additions/Alterations by Kristofer Hansson Aspman
#########################################################################
pc-dbg: PC_FLAGS+= -DDEBUG
pc-dbg: clean
	gcc -DPC -DDEBUG $(SRC) $(PROTO_SRC) -o bin/$(PROG).o

valgrind: PC_FLAGS+= -g -DDEBUG
valgrind: clean
	gcc $(PC_FLAGS) $(SRC) $(PROTO_SRC) -o bin/$(PROG).o
	@ echo "Running Valgrind memory tests..."
	valgrind --leak-check=yes bin/test.o

profiler: PC_FLAGS+= -lgcov -fprofile-arcs -ftest-coverage -DMASTER_TEST_SUITE -DAUTOMATED
profiler:
	gcc $(PC_FLAGS) $(CUNIT_SRC) $(SRC) $(PROTO_SRC) -o bin/$(TESTNAME).o -lcunit

## Works with v1.7 of LCov /Kristofer
gcov: clean
	make profiler
	@ echo "Compiled for gcov, now running testsuite..."
	$(TESTSUITE_OBJ)
	@ echo "After exec testsuite"
	gcov src/*.c
	mv bin/test_suite.o ./
	rm -fr ./covs/
	mkdir ./covs/
	lcov --directory ./covs --zerocounters 
	lcov --directory ./ --capture --output-file test_suite.o.info
	genhtml -o ./covs/ test_suite.o.info
	@ echo "genhtml created files in covs-folder"
	make moveGCovFiles

## Works with v1.9 of LCov /Kristofer
gcov2: clean
	make profiler
	@ echo "Compiled for gcov, now running testsuite..."
	$(TESTSUITE_OBJ)
	@ echo "After exec testsuite"
	gcov -b -c src/*.c
	mv bin/test_suite.o ./
	rm -fr ./covs/
	mkdir ./covs/
	lcov --directory ./covs --zerocounters 
	lcov --directory ./ --capture --output-file test_suite.o.info
	genhtml --branch-coverage -o ./covs/ test_suite.o.info
	@ echo "genhtml created files in covs-folder"
	make moveGCovFiles

moveGCovFiles:
	mv test_suite.* test/
#	mv ..*c.gcov test/
	mv *.gcno test/
	mv *.gcda test/
	@ echo ".gcov-files moved to test-folder"

clean:
	rm -fr ./covs/
	@ cd bin && rm -f $(FILES_TO_REMOVE)
	@ echo "Project cleaned"
#########################################################################

version:
	@ echo $(VERS)

help:
	@ echo "Check: \n	- the declared usb port\n	- if all required folders exist\n	- if your code includes 'WProgram.h'\n	- if you call 'init()'\n	- try removing '@' from this makefile to get more output"

# reprogram the fuses for the right clock source
#fuse:
#	avrdude -p atmega168 -c stk200 -U lfuse:w:0x62:m

.PHONY : clean compile test uno mega pc install help version
