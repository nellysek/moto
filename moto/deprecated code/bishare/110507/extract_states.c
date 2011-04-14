#include <stdio.h>
#include "extract_states.h"
/* state positions in bits*//*00000000*/
/* @uthor Bishare Sufi*/
/* unsigned char 1 byte = 8 bits the size of the message
   using hexadecimal*/
/* code for generating and extracting states */
/* this code was created in the first sprint of the project, it is not used 
   for the project, because the group had different solutions and picked up one 
   of them */  

#define HOVER 0xC0
#define FORWARD 0xE3
#define TURN_RIGHT 0xEC         
#define TURN_LEFT 0xCE
#define BACKWARD 0xC3
#define PANIC_STATE 0x80
#define START_STATE 0x40
#define INCREASE_MOTOR 0x20
#define DECREASE_MOTOR 0x10
#define RIGHT_MOTOR 0x8
#define LEFT_MOTOR 0x4
#define FRONT_MOTOR 0x2
#define REAR_MOTOR 0x1
#define STOP_STATE 0x0

/* increase motor power function */
unsigned char generate_value_Inc_motor(unsigned char motor){
   return motor | INCREASE_MOTOR; /*motor together with INCREASE_MOTOR*/
}

/* decrease motor power function */
unsigned char generate_value_Dec_motor(unsigned char motor){
   return motor | DECREASE_MOTOR; /*motor together with DECREASE_MOTOR*/
}

/* control motor function */
unsigned char generate_value_Con_motor(unsigned char motor){
   return motor;
}

/* panic motor function */
unsigned char generate_value_Pan_motor(unsigned char motor){
   return motor | PANIC_STATE; /*motor together with PANIC_MOTOR*/
}

void extract(unsigned char st){
        if(st == START_STATE){ /*constant state*/ 
		printf("Start State");
	}
        else if(st == FORWARD){ 
		         printf("Forward State");
        }
        else if(st == BACKWARD){ 
		         printf("Backward State");
        }
        else if(st == TURN_LEFT){ 
		         printf("Turn left State");
        }
        else if(st == TURN_RIGHT){ 
		         printf("Turn Right State");
        }
	else if(st == STOP_STATE){ // constant state  
		printf("Stop State");
	}
        else{
		if(st & INCREASE_MOTOR){
			printf("Increase State ");
        	}
                else{
			printf("Decrease State ");
        	}

		if(st & PANIC_STATE){
			printf("Panic State ");
        	}
		else{
			printf("Normal State ");
		}

                if(st & FRONT_MOTOR){
			printf("Front Motor "); 
                }  
                if(st & REAR_MOTOR){
			printf("Rear Motor "); 
                }
		if(st & LEFT_MOTOR){
			printf("Left Motor ");
		}
		if(st & RIGHT_MOTOR){  
			printf("Right Motor ");
		}
	}
	printf("\n");
}

int main(void){

	unsigned char st;

	st = generate_value_Inc_motor(LEFT_MOTOR);/* set state */
	extract(st); /* extract state */
        st = generate_value_Inc_motor(RIGHT_MOTOR);
	extract(st);
        st=generate_value_Inc_motor(LEFT_MOTOR | RIGHT_MOTOR);
	extract(st); /* here is the same, but both together */


	st = generate_value_Inc_motor(FRONT_MOTOR);
	extract(st); 
        st = generate_value_Inc_motor(REAR_MOTOR);
	extract(st); 
        st=generate_value_Inc_motor(FRONT_MOTOR | REAR_MOTOR);
	extract(st); 


        st = generate_value_Dec_motor(LEFT_MOTOR); /* set state */
	extract(st); /* get state */
        st = generate_value_Dec_motor(RIGHT_MOTOR);
	extract(st); 
        st =generate_value_Dec_motor(LEFT_MOTOR | RIGHT_MOTOR);
	extract(st); /* here is the same, but both together */


        st = generate_value_Dec_motor(FRONT_MOTOR);
	extract(st); 
        st = generate_value_Dec_motor(REAR_MOTOR);
	extract(st); 
        st =generate_value_Dec_motor(FRONT_MOTOR | REAR_MOTOR); 
	extract(st);


        st = generate_value_Con_motor(FORWARD); /* set state */
	extract(st); /* get state */
        st = generate_value_Con_motor(BACKWARD);
	extract(st); 
        st = generate_value_Con_motor(TURN_LEFT);
	extract(st); 
        st = generate_value_Con_motor(TURN_RIGHT);
	extract(st); 


	st = generate_value_Pan_motor(LEFT_MOTOR); /* set state */
	extract(st); /* extract state */
        st = generate_value_Pan_motor(RIGHT_MOTOR);
	extract(st); 
        st = generate_value_Pan_motor(LEFT_MOTOR | RIGHT_MOTOR);
	extract(st); 
        st = generate_value_Pan_motor(FRONT_MOTOR);
	extract(st);
        st = generate_value_Pan_motor(REAR_MOTOR);
        extract(st);
        st = generate_value_Pan_motor(FRONT_MOTOR | REAR_MOTOR);
	extract(st); 
        


	st = generate_value_Pan_motor(LEFT_MOTOR | INCREASE_MOTOR);
        extract(st); 
        st = generate_value_Pan_motor(RIGHT_MOTOR | INCREASE_MOTOR);
	extract(st); 
        st = generate_value_Pan_motor(LEFT_MOTOR | RIGHT_MOTOR | INCREASE_MOTOR);
	extract(st); 
        st = generate_value_Pan_motor(FRONT_MOTOR | INCREASE_MOTOR);
        extract(st); 
        st = generate_value_Pan_motor(REAR_MOTOR | INCREASE_MOTOR);
	extract(st); 
        st = generate_value_Pan_motor(FRONT_MOTOR | REAR_MOTOR | INCREASE_MOTOR);
        extract(st); /* here is the same, but get both together */
  
}


