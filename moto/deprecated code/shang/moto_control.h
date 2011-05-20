                                                        
                                             
/***************************************************************************
 * Copyright (C) 2011  Yu Shang
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
 * @author Yu Shang
 * @file moto_control.h
 * @description: the control of the motors functions.
 * @date 17-05-2011
 */
#include <stdint.h>

#define MOTORS 4 // number of motors
#define MAX_SPEED 100 // maximum speed to send to motors
#define NORMAL_SPEED 2 // increase speed in normal
#define PANIC_SPEED 4 // increase speed in panic model
#define SLEEP 60 // sleep ime when starting motors
#define MOTOR_STARTTIMES 10 // the times to increase the speed when start motors
#define HOVER_SPEED 4 //increase speed to hover 

#define MOTO_RIGHT 0 // right motor id
#define MOTO_LEFT 1 // left motor id
#define MOTO_REAR 2 // rear motor id
#define MOTO_FRONT 3 // front motor id

// motor structure
typedef 

struct motor
{
  int16_t speed;
  int16_t pinNumber;
} 

motor;

#define MOTOR_SIZE sizeof(motor)*4 // allocate motor size in memory

typedef motor* motor_ptr; // motor pointer shortcut

motor motors[MOTORS];

void initMotors(motor_ptr);  // init motors members
void startMotors(motor_ptr); // start motors
void stopMotors(motor_ptr); // stop motors
void setSpeed(motor_ptr, int16_t); // set the speed of just one motor 
void printStatus(motor_ptr); // print status of motors
void allMotors(motor_ptr, int16_t, char); // set for all motors
void frontMotors(motor_ptr, int16_t ,char); // set the front motors speed,if it is panic mode or not
void backMotors(motor_ptr, int16_t, char); // set the back motors speed, if it is panic mode or not
void rightMotors(motor_ptr, int16_t, char); // set the right motors speed, if it is panic mode or not
void leftMotors(motor_ptr, int16_t, char); // set the left motors speed, if it is panic mode or not

void moveUp(motor_ptr, char panic); // increas the speed if all motors, if it is panic mode or not
void moveDown(motor_ptr, char panic); // decrase the speed of all motors, if it is panic mode or not
void moveLeft(motor_ptr, char panic); // move left, if it is panic mode or not
void moveRight(motor_ptr, char panic); // move right, if it is panic mode or not
void moveHover(motor_ptr); // hover
void moveFrwrd(motor_ptr, char panic); // move forward, if it is panic mode or not
void moveBack(motor_ptr, char panic); // move backward, if it is panic mode or not

void moveMotor(motor_ptr, int motorNumber, char incease,char panic); // turning only one motor
