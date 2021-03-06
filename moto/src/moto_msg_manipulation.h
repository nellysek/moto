                                                        
                                             
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
 * @file moto_msg_manipulation.h
 * @version v0.03
 * @date 2011-05-18
 *
 * @brief Intended to include the necessary tools to handle\n
   the binary motor control msg.\n
   Defines the types msg and msg_pointer, frequently used\n
   within the code of the motor control component.\n
   Various tools such as macros for casting and function\n
   for printing are found here.
 *
 * @history 2011-04-03: First version (Kristofer).
            2011-04-07: Implemented ifdefs (Kristofer).
            2011-05-08: Cleaned up a bit and added some comments.
            2011-05-18: Removed ifdef ARDUINO (Kristofer).
 */
#ifndef MOTO_MSG_MANIPULATION_H
    #define MOTO_MSG_MANIPULATION_H
#include <stdint.h>

/* Casts a uint8_t into a pointer of type msg_pointer */
#define INT_TO_BITFIELD(a) *(msg_pointer)a

/* Casts a msg_pointer into a uint8_t */
#define BITFIELD_TO_CHAR(a) *(uint8_t*)a

/* !
 * @typedef msg
 * @brief Big endian control message. This is the actual bitfield used
 * throughout the motor control component.
 */
typedef struct control_message{
  uint8_t rear :1;
  uint8_t front :1;
  uint8_t left :1;
  uint8_t right :1;
  uint8_t panic :1;
  uint8_t increase :1;
  uint8_t ID :2;
} msg, *msg_pointer;

void printMsg(msg_pointer mp);
#endif
