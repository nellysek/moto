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
#include "state_definitions.h"
#include "moto_msg_parsing.h"

/*
*it checks the argument inwhich the function was called
* and call a function with tha same argument 
*/
void left_motor( uint8_t command){
    switch (command){
        case INCREASE:{
			calc_left_motors_speed(INCREASE);
			break;
		}
        case DECREASE:{
			calc_left_motors_speed(DECREASE);
			break;
		}
        case PANIC_INCREASE:{
			calc_left_motors_speed(PANIC_INCREASE);
			break;
		}
        case PANIC_DECREASE:{
			calc_left_motors_speed(PANIC_DECREASE);
			break;
		}
    }
}

/*
*it checks the argument inwhich the function was called
* and call a function with tha same argument 
*/

void right_motor(uint8_t command){
    switch (command){
        case INCREASE:{
			calc_right_motors_speed(INCREASE);
			break;
		}
        case DECREASE:{
			calc_right_motors_speed(DECREASE);
			break;
		}
        case PANIC_INCREASE:{
			calc_right_motors_speed(PANIC_INCREASE);
			break;
		}
        case PANIC_DECREASE:{
			calc_right_motors_speed(PANIC_DECREASE);
			break;
		}
    }
}

/*
*it checks the argument inwhich the function was called
* and call a function with tha same argument 
*/

void front_motor(uint8_t command){
    switch (command){
        case INCREASE:{
			calc_front_motors_speed(INCREASE);
			break;
		}
        case DECREASE:{
			calc_front_motors_speed(DECREASE);
			break;
		}
        case PANIC_INCREASE:{
			calc_front_motors_speed(PANIC_INCREASE);
			break;
		}
        case PANIC_DECREASE:{
			calc_front_motors_speed(PANIC_DECREASE);
			break;
		}
    }
}

/*
*it checks the argument inwhich the function was called
* and call a function with tha same argument 
*/

void rear_motor(uint8_t command){
    switch (command){
        case INCREASE:{
			calc_rear_motors_speed(INCREASE);
			break;
		}
        case DECREASE:{
			calc_rear_motors_speed(DECREASE);
			break;
		}
        case PANIC_INCREASE:{
			calc_rear_motors_speed(PANIC_INCREASE);
			break;
		}
        case PANIC_DECREASE:{
			calc_rear_motors_speed(PANIC_DECREASE);
			break;
		}
    }
}

/*
*it checks the argument inwhich the function was called
* and call a differnt function with argument to adjust each motors with 
* valid values
*/

void all_motors_speed(uint8_t command){
    switch (command){
        case START_MOTOR:{
	    calc_rear_motors_speed(INCREASE);
            calc_front_motors_speed(INCREASE);
            calc_left_motors_speed(INCREASE);
            calc_right_motors_speed(INCREASE);
			break;
		}
        case STOP_MOTOR:{
	    calc_rear_motors_speed(DECREASE);
	    calc_front_motors_speed(DECREASE);
            calc_right_motors_speed(DECREASE);
            calc_left_motors_speed(DECREASE);
			break;
		}
        case INCREASE_ALL:{
	    calc_rear_motors_speed(INCREASE);
            calc_front_motors_speed(INCREASE);
            calc_right_motors_speed(INCREASE);
            calc_left_motors_speed(INCREASE);
			break;
		}
        case DECREASE_ALL:{
	    calc_rear_motors_speed(DECREASE);
            calc_front_motors_speed(DECREASE);
            calc_right_motors_speed(DECREASE);
            calc_left_motors_speed(DECREASE);
			break;
        }
        case PANIC_INCREASE_ALL:{
	    calc_rear_motors_speed(PANIC_INCREASE);
            calc_front_motors_speed(PANIC_INCREASE);
            calc_right_motors_speed(PANIC_INCREASE);
            calc_left_motors_speed(PANIC_INCREASE);
			break;
		}
        case PANIC_DECREASE_ALL:{
	    calc_rear_motors_speed(PANIC_DECREASE);
            calc_front_motors_speed(PANIC_DECREASE);
            calc_right_motors_speed(PANIC_DECREASE);
            calc_left_motors_speed(PANIC_DECREASE);
			break;
		}
    }
}

/*
*it checks the argument inwhich the function was called
* and call a differnt function with argument to adjust each motors with 
* valid values
*/

void movement_command(uint8_t command){
    switch (command){
        case TURN_LEFT:{
	    calc_left_motors_speed(DECREASE);
            calc_right_motors_speed(INCREASE);
			break;
		}
        case TURN_RIGHT:{
	    calc_left_motors_speed(INCREASE);
            calc_right_motors_speed(DECREASE);
			break;
		}
        case FORWARD:{
	    calc_rear_motors_speed(INCREASE);
            calc_front_motors_speed(DECREASE);
			break;
		}
        case BACKWARD:{
	    calc_rear_motors_speed(DECREASE);
            calc_front_motors_speed(INCREASE);
			break;
		}
    }
}

/*
*it checks the argument inwhich the function was called
* and calculate the left motor value to be added or subtracted
*if it is with in the boundries it return the result 
* but if it is less or more than the limit it print out error msg
*    DECREASE= 19, INCREASE= 20
*    DECREASE+1 = 20, which is the same as ( - )INCREASE 
*/

/* calculate left motor speed */
void calc_left_motors_speed( uint8_t command){
    if(command == INCREASE && current_left_speed + INCREASE <= MAX_SPEED){
        current_left_speed += INCREASE;
        printf("The current left motor speed is : %d\n",current_left_speed);
    }else if(command == DECREASE && 
	current_left_speed - (DECREASE + 1)>= MIN_SPEED){
        current_left_speed -= DECREASE+1;
        printf("The current left motor speed is : %d\n",current_left_speed);
    }
    else if(command == PANIC_INCREASE && 
	current_left_speed + (PANIC_INCREASE )<= MAX_SPEED){
        current_left_speed += PANIC_INCREASE;
        printf("The current left motor speed is : %d\n",current_left_speed);
    }else if(command == PANIC_DECREASE && 
	current_left_speed - (PANIC_DECREASE + 1) <= MIN_SPEED){
        current_left_speed -= PANIC_DECREASE + 1;
        printf("The current left motor speed is : %d\n",current_left_speed);
    }else{
        printf("left motor pulse is less or more than the limited value\n");
	}
}

/*
*it checks the argument inwhich the function was called
* and calculate the right motor value to be added or subtracted
*if it is with in the boundries it return the result 
* but if it is less or more than the limit it print out error msg
*    DECREASE= 19, INCREASE= 20
*    DECREASE+1 = 20, which is the same as ( - )INCREASE 
*/

/* calculate right motor speed */    
void calc_right_motors_speed(uint8_t command){
    if(command == INCREASE && current_right_speed + INCREASE <= MAX_SPEED){
        current_right_speed += INCREASE;
        printf("The current right motor speed: %d\n",current_right_speed);
    }else if(command == DECREASE && 
	current_right_speed - (DECREASE + 1)>= MIN_SPEED){
        current_right_speed -= DECREASE + 1;
        printf("The current right motor speed:%d\n",current_right_speed);
    }else if(command == PANIC_INCREASE && 
	current_right_speed + PANIC_INCREASE <= MAX_SPEED){
        current_right_speed += PANIC_INCREASE;
        printf("The current right motor speed is: %d\n",current_right_speed);
    }else if (command == PANIC_DECREASE && 
	current_right_speed - (PANIC_DECREASE +1) >= MIN_SPEED){
        current_right_speed -= PANIC_DECREASE +1;
        printf("The current left motor speed is : %d\n",current_right_speed);
    }else{
        printf("Right motor pulse is less or more than the limited value\n");
	}
}

/*
*it checks the argument inwhich the function was called
* and calculate the rear motor value to be added or subtracted
*if it is with in the boundries it return the result 
* but if it is less or more than the limit it print out error msg
*    DECREASE= 19, INCREASE= 20
*    DECREASE+1 = 20, which is the same as ( - )INCREASE 
*/
/* calc front motor speed */
void calc_front_motors_speed( uint8_t command){
    if(command == INCREASE && current_front_speed + INCREASE <= MAX_SPEED){
        current_front_speed += INCREASE;
        printf("The current front motor speed is : %d\n", current_front_speed);
    }else if(command == DECREASE && 
	current_front_speed - (DECREASE + 1)>= MIN_SPEED){
        current_front_speed -= DECREASE + 1;
        printf("The current front motor speed is:%d\n",current_front_speed);
    }else if(command == PANIC_INCREASE && 
	current_front_speed + PANIC_INCREASE <= MAX_SPEED){
        current_front_speed += PANIC_INCREASE;
        printf("The current front motor speed:%d\n",current_front_speed);
    }else if (command == PANIC_DECREASE && 
	current_front_speed - (PANIC_DECREASE + 1)>= MIN_SPEED){
        current_front_speed -= PANIC_DECREASE + 1;
        printf("The current front motor speed is: %d\n",current_front_speed);
    }else{
        printf("Front motor pulse is less or more than the limited value\n");
	}
}
/*
*it checks the argument inwhich the function was called
* and calculate the rear motor value to be added or subtracted
*if it is with in the boundries it return the result 
* but if it is less or more than the limit it print out error msg
*        DECREASE= 19, INCREASE= 20
*        DECREASE+1 = 20, which is the same as ( - )INCREASE 
*/
    
/* calc front motor speed */
void calc_rear_motors_speed( uint8_t command){
    if(command == INCREASE && 
		current_rear_speed + INCREASE <= MAX_SPEED){
        current_rear_speed += INCREASE;
        printf("The current rear motor speed is : %d\n",current_rear_speed);
    }else if(command == DECREASE && 
		current_rear_speed -(DECREASE + 1)>= MIN_SPEED){
        current_rear_speed -= DECREASE + 1;
        printf("The current rear motor speed is : %d\n",current_rear_speed);
    }else if(command == PANIC_INCREASE && 
		current_rear_speed + PANIC_INCREASE <= MAX_SPEED){
        current_rear_speed += PANIC_INCREASE;
        printf("The current rear motor speed is : %d\n",current_rear_speed);
    }else if(command == PANIC_DECREASE && 
		current_rear_speed - (PANIC_DECREASE +1) >= MIN_SPEED){
        current_rear_speed -= PANIC_DECREASE +1;
        printf("The current rear motor speed is : %d\n",current_rear_speed);
    }else{
        printf("Rear motor pulse is less or more than the limited value\n ");
    }
}
