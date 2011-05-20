                                                        
                                             
/***************************************************************************
 * Copyright (C) 2011  Kristofer Hansson Aspman
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
 * @author Kristofer Hansson Aspman
 * @file moto_msg_handler.h
 * @version v0.03
 * @date 2011-05-18
 * @brief The typedef of the bitfield struct and
          all the prototypes for the functions used
          by tools.c, motor_control.c and parser.c.
 */

#ifndef MOTO_MSG_HANDLER_H
    #define MOTO_MSGHANDLER_H
#include <stdint.h>

#ifdef ARDUINO_DBG
    #define ARDUINO
#endif
#ifdef ARDUINO
   #include "WProgram.h"
#elif defined PC
   #include <stdio.h>
#endif

/* Parser functions */
int examineID(msg_pointer mp);
void controlMotors(msg_pointer mp);
void specialMotorCommand(msg_pointer mp);

#endif
