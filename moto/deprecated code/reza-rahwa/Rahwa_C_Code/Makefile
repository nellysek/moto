
 start: moto_control.o moto_msg_parsing.o moto_init.o
	cc -o start moto_init.o moto_msg_parsing.o moto_control.o
 
moto_init.o: moto_init.c
	cc -c moto_init.c

moto_control.o: moto_control.c
	cc -c moto_control.c

moto_msg_parsing.o: moto_msg_parsing.c
	cc -c moto_msg_parsing.c
clean:
	rm *.o
