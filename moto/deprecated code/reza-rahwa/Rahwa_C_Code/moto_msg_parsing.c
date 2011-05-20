
/***************************************************************************
 * Copyright (C) 2011  Rahwa Bahta
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
#include <stdint.h>
#include "moto_control.h"
#include "moto_msg_parsing.h"
#include "state_definitions.h"

/*
*This function checks all possible MSG the will be send from moto_init.c
*and if it machs with listed cases, it calls function in moto_control.c
*to adjust the motor pulse, but if the MSG is not in the list 
*it returns error MSG
*/
void msg_parsing (uint8_t msg){
    switch(msg) {
        case START_MOTOR:{
            all_motors_speed(START_MOTOR);
            break;
        }
        case STOP_MOTOR:{
            all_motors_speed(STOP_MOTOR);
            break;
        }
        case INCREASE_REAR_MOTOR:{
            rear_motor(INCREASE);
            break;
        }
        case DECREASE_REAR_MOTOR:{
            rear_motor(DECREASE);
            break;
        }
        case INCREASE_FRONT_MOTOR:{
            front_motor(INCREASE);
            break;
        }
        case DECREASE_FRONT_MOTOR:{
            front_motor(DECREASE);
            break;
        }
        case INCREASE_LEFT_MOTOR:{
            left_motor(INCREASE);
            break;
        }
        case DECREASE_LEFT_MOTOR:{
            left_motor(DECREASE);
            break;
        }
        case INCREASE_RIGHT_MOTOR:{
            right_motor(INCREASE);
            break;
        }
        case DECREASE_RIGHT_MOTOR:{
            right_motor(DECREASE);
            break;
        }
        case DECREASE_FRONT_INCREASE_REAR:{
            front_motor(DECREASE); rear_motor(INCREASE);
            break;
        }
        case DECREASE_REAR_INCREASE_FRONT:{
            rear_motor(DECREASE); front_motor(INCREASE);
            break;
        }
        case DECREASE_RIGHT_INCREASE_LEFT:{
            right_motor(DECREASE); left_motor(INCREASE);
            break;
        }
        case DECREASE_LEFT_INCREASE_RIGHT:{
            left_motor(DECREASE); right_motor(INCREASE);
            break;
        }
        case PANIC_INCREASE_REAR_MOTOR:{
            rear_motor(PANIC_INCREASE);
            break;
        }
        case PANIC_DECREASE_REAR_MOTOR:{
            rear_motor(PANIC_DECREASE);
            break;
        }
        case PANIC_INCREASE_FRONT_MOTOR:{
            front_motor(PANIC_INCREASE);
            break;
        }
        case PANIC_DECREASE_FRONT_MOTOR:{
            front_motor(PANIC_DECREASE);
            break;
        }
        case PANIC_INCREASE_LEFT_MOTOR:{
            left_motor(PANIC_INCREASE);
            break;
        }
        case PANIC_DECREASE_LEFT_MOTOR:{
            left_motor(PANIC_DECREASE);
            break;
        }
        case PANIC_INCREASE_RIGHT_MOTOR:{
            right_motor(PANIC_INCREASE);
            break;
        }
        case PANIC_DECREASE_RIGHT_MOTOR:{
            right_motor(PANIC_DECREASE);
            break;
        }
        case TURN_RIGHT:{
            movement_command(TURN_RIGHT);
            break;
        }
        case TURN_LEFT:{
            movement_command(TURN_LEFT);
            break;
        }
        case PANIC_INCREASE_ALL:{
            all_motors_speed(INCREASE_ALL);
            break;
        }
        default:{
            printf("Error msg\n");
        }
    }
}