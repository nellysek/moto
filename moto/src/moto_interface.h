                                                        
                                             
/***************************************************************************
 * Copyright (C) 2011  Björn Eriksson, Kristofer Hansson Aspman,
 *                     Magnus Bergqvist
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
 * @author Kristofer Hansson Aspman, Björn Eriksson, Magnus Bergqvist
 * @file moto_interface.c
 * @version v0.05
 * @date 2011-05-17
 * @history 2011-05-17 - Update after code review \n
                        (Magnus) \n
            2011-05-11 - Worked with ifdefs \n
                        (Magnus, Björn) \n
            2011-04-26 - Major cleanup and restructuring of the code\n
                        (Magnus, Björn, Kristofer) \n
            2011-04-10 - Created first version \n
                        (Magnus, Björn, Kristofer) \n

 * @brief Contains the implementations of moto_init and moto_run.\n
          Global variables set are: moto_cyclesSinceLastMsg (stores the
          amount of cycles since last message was written to the protocol
          by the movement component).
 */

#ifndef MOTO_INTERFACE_H
    #define MOTO_INTERFACE_H
#include <stdint.h>
#ifdef ARDUINO_DBG
    #define ARDUINO
#endif

#ifdef ARDUINO
    #include "WProgram.h"
    #include "../include/Servo.h"
#endif

#ifdef ARDUINO
extern Servo escRight;
extern Servo escLeft;
extern Servo escFront;
extern Servo escRear;
#endif

/* 
 * Stores the number of cycles since the last message was written to the
 * protocol by the movement group.
 */
static int moto_cyclesSinceLastMsg;

int16_t moto_init(void);
int16_t moto_run(void);
#endif
