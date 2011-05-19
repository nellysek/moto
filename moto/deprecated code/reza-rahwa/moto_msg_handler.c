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

#include <stdint.h>
#include "moto_msg_handler.h"
#include "moto_driver_functions.h"
#include "moto_state_definitions.h"

/*
* to get the message and redirect to propper function
*/
uint8_t examineID(msg_pointer mp){
    switch(mp->ID){
        case START_ID:{
            moto_startMotors();
            break;
        }
        case STOP_ID:{
            moto_stopMotors();
            break;
        }
        case CONTROL_ID:{
            controlMotors(mp);
            break;
        }
        case SPECIAL_COMMAND_ID:{
            specialMotorCommand(mp);
            break;
        }
    }
    return 0;
}

/*
* get the message from examineID function
* and call related motors to re-act
*/
void controlMotors(msg_pointer mp){
    if(mp->LEFT)    moto_left_motor(mp->INCREASE,mp->PANIC);
    if(mp->RIGHT)    moto_right_motor(mp->INCREASE,mp->PANIC);
    if(mp->FRONT)    moto_front_motor(mp->INCREASE,mp->PANIC);
    if(mp->REAR)    moto_rear_motor(mp->INCREASE,mp->PANIC);
}

/*
* Handle special message called by examineID
* does start,stop turning and strafing
*/
void specialMotorCommand(msg_pointer mp){
    switch(*((uint8_t*)mp)){
        case FORWARD:{
            moto_rear_motor(1,0);
            moto_front_motor(0,0);
            break;
        }
        case BACKWARD:{
            moto_rear_motor(0,0);
            moto_front_motor(1,0);
            break;
        }
        case TURN_LEFT:{
            break;
        }
        case TURN_RIGHT:{
            break;
        }
        case STRAFE_LEFT:{
            moto_right_motor(1,0);
            moto_left_motor(0,0);
            break;
        }
        case STRAFE_RIGHT:{
            moto_right_motor(0,0);
            moto_left_motor(1,0);
            break;
        }
    }
}
