                                                        
                                             
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
 * @file motorcontrol.h
 * @version v0.03
 * @date 2011-03-26
 * @brief Header file containing prototypes of functions in \n
          motorcontrol.c and also predefined values. \n
          not used because we decided to have void functions \n
          in the architecture and before we knew that the Servo.h \n
          will be used.
 * @history 2011-04-03: merged with moto_driver_functions.h
 */
#include <stdint.h>

/* defines the motor pins on the arduino */
#define LEFT_MOTOR 6
#define RIGHT_MOTOR 3
#define FRONT_MOTOR 4
#define REAR_MOTOR 5

/* prototypes for the functions */
void startMotors();
void stopMotors();
uint8_t increaseMotorPulse(uint8_t motor, uint8_t pulse);
uint8_t increaseMotorPulseX2(uint8_t motor, uint8_t pulse);
uint8_t decreaseMotorPulse(uint8_t motor, uint8_t pulse);
uint8_t decreaseMotorPulseX2(uint8_t motor, uint8_t pulse);

/*
 * from the header file moto_driverfunctions.h \n
 * a struct which were supposed to be sent to the movement group with \n
 * all the different pulses.
 * This struct for sending to movement were deprecated \n
 * due to the implementation of movement when they had \n
 * 3 different "groups" in one.
 */
struct pulses{
    uint16_t right;
    uint16_t left;
    uint16_t front;
    uint16_t rear;
};
