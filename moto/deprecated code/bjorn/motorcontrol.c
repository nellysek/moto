                                                        
                                             
/***************************************************************************
 * Copyright (C) 2011  Björn Eriksson
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
/*!
 * @author Björn Eriksson      
 * @file motorcontrol.c
 * @version v0.01
 * @date 2011-03-26
 * @brief Contains the functions that sets the pulse width of the \n
          different motors. \n
          not used because we decided to have void functions \n
          in the architecture and before we knew that the Servo.h \n
          will be used. The reason for returning the pulse was to be \n
          easier to test.
 * @history 2011-04-03: merged with moto_driver_functions.c
 */

#include "motorcontrol.h"
#include <stdint.h>
uint8_t leftPulse = 0;
uint8_t rightPulse = 0;
uint8_t frontPulse = 0;
uint8_t rearPulse = 0;


/* !
 * @author Björn Eriksson
 * @function startMotors
 * @param void
 * @return void
 * @brief startMotors sets the pulse width to a level where all motors \n
          starts spinning but the drone does not lift off.
 */
void startMotors() {
    leftPulse = 62;
    rightPulse = 62;
    frontPulse = 62;
    rearPulse = 62;
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
}

/* !
 * @author Björn Eriksson
 * @function stopMotors
 * @param void
 * @return void
 * @brief stopMotors stops all motors, i.e. sets the pulse width to a \n
          value where all the motors stops turning.
 */
void stopMotors() {
    leftPulse = 0;
    rightPulse = 0;
    frontPulse = 0;
    rearPulse = 0;
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
}

/* !
 * @author Björn Eriksson
 * @function stopMotors
 * @param uint8_t, uint8_t
 * @return uint8_t
 * @brief increaseMotorPulse increase the pulse width of one \n
          specific motor by 3. \n
          controls that to pulse width are not above 255.
 */
uint8_t increaseMotorPulse(uint8_t motor, uint8_t pulse) {
    if(pulse < 252) {
        pulse = pulse + 3;
        analogWrite(motor, pulse);
        return pulse;
    }
    return 255;
}

/* !
 * @author Björn Eriksson
 * @function stopMotors
 * @param uint8_t, uint8_t
 * @return uint8_t
 * @brief increaseMotorPulseX2 increase the pulse width of one \n
          specific motor by 6. \n
          controls that to pulse width are not above 255.
 */
uint8_t increaseMotorPulseX2(uint8_t motor, uint8_t pulse) {
    if(pulse < 249) {
        pulse = pulse + 6;
        analogWrite(motor, pulse);
        return pulse;
    }
    return 255;
}

/* !
 * @author Björn Eriksson
 * @function stopMotors
 * @param uint8_t, uint8_t
 * @return uint8_t
 * @brief decreaseMotorPulse decrease the pulse width of one \n
          specific motor by 3. \n
          controls that to pulse width are not below 3.
 */
uint8_t decreaseMotorPulse(uint8_t motor, uint8_t pulse) {
    if(pulse > 3) {
        pulse = pulse - 3;
        analogWrite(motor, pulse);
        return pulse;
    }	
    return 3;
}

/* !
 * @author Björn Eriksson
 * @function stopMotors
 * @param uint8_t, uint8_t
 * @return uint8_t
 * @brief decreaseMotorPulseX2 decrease the pulse width of one \n
          specific motor by 6. \n
          controls that to pulse width are not below 3.
 */
uint8_t decreaseMotorPulseX2(uint8_t motor, uint8_t pulse) {
    if(pulse > 6) {
        pulse = pulse - 6;
        analogWrite(motor, pulse);
        return pulse;
    }	
    return 3;
}
	
/* !
 * @author Björn Eriksson
 * @function sendMsg
 * @param void
 * @return void
 * @brief sendMsg creates a struct which are sent to movement \n
          for them to know the current pulses. \n
          This function for sending the struct were deprecated \n
          due to the implementation of movement when they had \n
          3 different "groups" in one.          
 */
void sendMsg(void){
    struct pulses currentPulsess = {rightPulse, leftPulse, 
                                    frontPulse, rearPulse};
    proto_write_move(currentPulses);
}	
