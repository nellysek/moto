
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

#ifndef MOTO_DRIVER_FUNCTIONS_H
#define MOTO_DRIVER_FUNCTIONS_H

#define NORMAL_STEP 1
#define PANIC_STEP 2

#define START_MOTOR_VAL 200
#define STOP_MOTOR_VAL 0
#define HOVER_MOTOR_VAL 1000

#define MAX_MOTOR_VAL 2000
#define MIN_MOTOR_VAL 100

/*Motor pulse modification*/
void moto_startMotors(void);
void moto_stopMotors(void);
void moto_hover(void);

void moto_left_motor(uint8_t,uint8_t);
void moto_right_motor(uint8_t,uint8_t);
void moto_front_motor(uint8_t,uint8_t);
void moto_rear_motor(uint8_t,uint8_t);

uint8_t applyPulse(uint8_t, uint8_t );

#endif