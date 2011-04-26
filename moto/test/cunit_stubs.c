/*!
 * @file cunit_stubs.c
 * @brief Stub functions for use during testing.
 * @date 2011-04-18
 * @author Magnus Bergqvist
 * @version 1
 * @history 2011-04-18 - created
 * @details The functions in cunit_stubs.c is used during testing to \n
            replace any arduino library function that is called within \n
            the software.
 */
#include <stdio.h>
#include <stdint.h>
#include "cunit_stubs.h"
#include "../src/moto_driver_functions.h"

/* writeMicroseconds from servo library from arduino standard libraries */
void writeMicroseconds(unsigned char value){
    fprintf(stdout, "writeMicroseconds received %d\n", value);
}

/* readMicroseconds from servo library from arduino standard libraries */
unsigned int readMicroseconds(void){
    fprintf(stdout, "readMicroseconds was called\n");
}

/* attach from servo library from arduino standard libraries */
unsigned char attach(unsigned char pin){
    fprintf(stdout, "attach was called for pin %d\n", pin);
}

/* analogWrite from arduino standard libraries, used for ordinary pwm out */
void analogWrite(int motor, uint16_t pulse){
    
    if(motor == LEFT_MOTOR){
        fprintf(stdout, "\nLEFT_MOTOR received %d\n", pulse);
    }
    if(motor == RIGHT_MOTOR){
        fprintf(stdout, "\nRIGHT_MOTOR received %d\n", pulse);
    }
    if(motor == FRONT_MOTOR){
        fprintf(stdout, "\nFRONT_MOTOR received %d\n", pulse);
    }
    if(motor == REAR_MOTOR){
        fprintf(stdout, "\nREAR_MOTOR received %d\n", pulse);
    }
}


