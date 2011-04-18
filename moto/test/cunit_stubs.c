#include <stdio.h>
#include "cunit_stubs.h"
#include "../src/moto_driver_functions.h"

void writeMicroseconds(unsigned char value){
    fprintf(stdout, "writeMicroseconds received %d\n", value);
}
unsigned int readMicroseconds(void){
    fprintf(stdout, "readMicroseconds was called\n");
}
unsigned char attach(unsigned char pin){
    fprintf(stdout, "attach was called for pin %d\n", pin);
}


void analogWrite(int motor, unsigned char pulse){
    
    if(motor == LEFT_MOTOR){
        fprintf(stdout, "LEFT_MOTOR received %d\n", pulse);
    }
    if(motor == RIGHT_MOTOR){
        fprintf(stdout, "RIGHT_MOTOR received %d\n", pulse);
    }
    if(motor == FRONT_MOTOR){
        fprintf(stdout, "FRONT_MOTOR received %d\n", pulse);
    }
    if(motor == REAR_MOTOR){
        fprintf(stdout, "REAR_MOTOR received %d\n", pulse);
    }
}


