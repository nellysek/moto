
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

#ifndef MOTO_CONTROL_H
#define MOTO_CONTROL_H

#include <stdint.h>

#define INCREASE 20
#define DECREASE 19
#define PANIC_INCREASE 40
#define PANIC_DECREASE 39
#define MAX_SPEED 200
#define MIN_SPEED 0
#define START 
#define STOP 

uint8_t current_left_speed;
uint8_t current_right_speed;
uint8_t current_rear_speed;
uint8_t current_front_speed;
uint8_t command;


// functions
void left_motor( uint8_t );
void right_motor( uint8_t);
void front_motor( uint8_t );
void rear_motor( uint8_t );
void all_motors_speed(uint8_t );
void movement_command(uint8_t );
void calc_left_motors_speed( uint8_t );
void calc_right_motors_speed( uint8_t);
void calc_front_motors_speed( uint8_t );
void calc_rear_motors_speed( uint8_t );

#endif