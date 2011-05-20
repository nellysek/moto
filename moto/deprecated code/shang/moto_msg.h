                                                        
                                             
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
 * @file moto_msg.h
 * @description: the message for the motors functions
 * @date 17-05-2011
 */

#ifdef ARDUINO
   #include "WProgram.h"
#elif defined PC
   #include <stdio.h>
#endif

typedef 

// message structure, saving the message after parsing.
struct message
{
  char id; // id bit
  char incrase; // incrase bit
  char panic; // panic mode bit
  char right; // right bit
  char left; // left bit 
  char front; // front bit
  char back; // back bit
  int value // the message value
} 

  msg; // typedef the msg,instead of use message struct 


msg parseMessage(char message); // parse the message and get the strcture
void makeAction(motor_ptr ptr,msg msg); // do  message shows
