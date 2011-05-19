
/***************************************************************************
 * Copyright (C) 2011  Rahwa Bahta, Reza Moussavi
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

#include <stdio.h>
#include "moto_driver_functions.h"

uint16_t rightPulse; /* the pulse value for right motor */
uint16_t leftPulse; /* the pulse value for left motor */
uint16_t frontPulse; /* the pulse value for front motor */
uint16_t rearPulse; /* the pulse value for rear motor */

/*
* apply the Increase/Decrease and Panic/Normal values
* extracted from the message to the left motor
*/
void moto_left_motor(uint8_t increase,uint8_t panic){
    leftPulse = increase?
        applyPulse(leftPulse, panic?PANIC_STEP:NORMAL_STEP):
        applyPulse(leftPulse, panic?-PANIC_STEP:-NORMAL_STEP);
    printf("Left Puls: %d\n",leftPulse);
}

/*
* apply the Increase/Decrease and Panic/Normal values
* extracted from the message to the right motor
*/
void moto_right_motor(uint8_t increase,uint8_t panic){
    rightPulse = increase?
        applyPulse(rightPulse, panic?PANIC_STEP:NORMAL_STEP):
        applyPulse(rightPulse, panic?-PANIC_STEP:-NORMAL_STEP);
    printf("Right Puls: %d\n",rightPulse);
}

/*
* apply the Increase/Decrease and Panic/Normal values
* extracted from the message to the front motor
*/
void moto_front_motor(uint8_t increase,uint8_t panic){
    frontPulse = increase?
        applyPulse(frontPulse, panic?PANIC_STEP:NORMAL_STEP):
        applyPulse(frontPulse, panic?-PANIC_STEP:-NORMAL_STEP);
    printf("Front Puls: %d\n",frontPulse);
}

/*
* apply the Increase/Decrease and Panic/Normal values
* extracted from the message to the rear motor
*/
void moto_rear_motor(uint8_t increase,uint8_t panic){
    rearPulse = increase?
        applyPulse(rearPulse, panic?PANIC_STEP:NORMAL_STEP):
        applyPulse(rearPulse, panic?-PANIC_STEP:-NORMAL_STEP);
    printf("Rear Puls: %d\n",rearPulse);
}

/*
* set START values to all motors as it starts
*/
void moto_startMotors(void){
    leftPulse = START_MOTOR_VAL;
    rightPulse = START_MOTOR_VAL;
    frontPulse = START_MOTOR_VAL;
    rearPulse = START_MOTOR_VAL;
    printf("Starting all motors\n");
}

/*
* set STOP values to all motors as it stops
*/
void moto_stopMotors(void){
    rightPulse = STOP_MOTOR_VAL;
    leftPulse = STOP_MOTOR_VAL;
    frontPulse = STOP_MOTOR_VAL;
    rearPulse = STOP_MOTOR_VAL;
    printf("Stopping all motors\n");
}

/*
* set HOVER values to all motors as it is going to hover state
*/
void moto_hover(void){
    rightPulse = HOVER_MOTOR_VAL;
    leftPulse = HOVER_MOTOR_VAL;
    frontPulse = HOVER_MOTOR_VAL;
    rearPulse = HOVER_MOTOR_VAL;
    printf("Hovering\n");    
}

/*
* get the motor pulse value and the additional value
* regardless of the motor and the additional value's sign
* and return the new pulse value as long as it is within the boundaries
*/
uint8_t applyPulse(uint8_t motor,uint8_t val){
    uint8_t result=motor+val;
    if(result>MAX_MOTOR_VAL || result<MIN_MOTOR_VAL){
        result=motor;
    }
    return result;
}
