
motor: moto_run.o moto_driver_functions.o moto_msg_handler.o
	cc -o motor moto_run.o moto_driver_functions.o moto_msg_handler.o

moto_run.o: moto_run.c
	cc -c moto_run.c

moto_driver_functions.o: moto_driver_functions.c
	cc -c moto_driver_functions.c
 
moto_msg_handler.o: moto_msg_handler.c
	cc -c moto_msg_handler.c

clean:
	rm *.o
