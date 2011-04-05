parser: header.h motor_controls.c parser.c tools.c

	gcc -o moto motor_controls.c parser.c $(EXTRAGCCFLAGS)

testobjs: motor_controls.c header.h 
	gcc -o motor_controls.o -c motor_controls.c $(EXTRAGCCFLAGS)

testobjscov: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage
testobjscov: testobjs

testobjsgdb: EXTRAGCCFLAGS+= -g
testobjsgdb: testobjs

gdb: EXTRAGCCFLAGS+= -g
gdb: parser

gcovcalc: EXTRAGCCFLAGS+= -fprofile-arcs -ftest-coverage
gcovcalc: parser

clean:
	rm -f moto motor_controls.exe motor_controls.o *.gcov *.gcda *.gcno
