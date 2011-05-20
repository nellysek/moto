                                                        
                                             
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
 * @file moto_msg.c
 * @description: the message for the motors functions
 * @date 17-05-2011
 */

#ifdef ARDUINO
   #include "WProgram.h"
#elif defined PC
   #include <stdio.h>
#endif

#include <moto_control.h>
#include <moto_msg.h>

// parse the message and get the strcture
msg parseMessage(char message)
{
  char id = message >> 6; // shift to the id bits
  char incrase = message >> 5; // increase bit
  incrase  = incrase & 0x1; 
  char panic = message >> 4; // panic bit
  panic = panic & 0x1; 
  char right = message >> 3; // right bit
  right= right & 0x1;
  char left= message >> 2; // left bit
  left = left & 0x1;
  char front= message >> 1; // front bit
  front = front & 0x1;
  char back = message & 0x1; // back bit

  // set the message members
  msg m;
  m.id = id; 
  m.incrase = incrase;
  m.panic = panic;
  m.right= right;
  m.left = left;
  m.front = front;
  m.back = back;
  m.value = message;

  return m; // return the message structure
}

// pass a message and a motor pointer, make actions message show
void makeAction(motor_ptr ptr,msg msg)
{
  if (msg.id == 0x40) // start motors message
    {
      startMotors(ptr);
    }
  else if (msg.id == 0x0)  // stop motors message
    {
      stopMotors(ptr);
    }
  else if (msg.id == 0x2){ // id is payload

    if (msg.right)  
      {
	moveMotor(ptr, MOTO_RIGHT, msg.incrase, msg.panic);
      }
    if (msg.left) 
      {
	moveMotor(ptr, MOTO_LEFT, msg.incrase, msg.panic);	    
      }
    if (msg.front)
      {
	moveMotor(ptr, MOTO_REAR, msg.incrase, msg.panic);
      }
    if (msg.back)
      {
	moveMotor(ptr, MOTO_REAR, msg.incrase, msg.panic); 
      }
  } else if (msg.id == 0x3) // other panic situations
    {
      if (msg.value == 0xe3)
	{
	  moveMotor(ptr, MOTO_REAR, 1, msg.panic);
	  moveMotor(ptr, MOTO_FRONT, 0, msg.panic);
	}
      if (msg.value == 0XC3)
	{
	  moveMotor(ptr, MOTO_REAR, 0, msg.panic);
	  moveMotor(ptr, MOTO_FRONT, 1, msg.panic);
	}
      if (msg.value == 0xec)
	{
	  moveMotor(ptr, MOTO_LEFT, 1, msg.panic);
	  moveMotor(ptr, MOTO_RIGHT, 0, msg.panic);
	}
      if (msg.value == 0xcc)
	{
	  moveMotor(ptr, MOTO_LEFT, 0, msg.panic);
	  moveMotor(ptr, MOTO_RIGHT, 1, msg.panic);
	}
      if (msg.value == 0xaf)
	{
	  moveUp(ptr, msg.panic);
	}
      if (msg.value == 0x8f)
	{
	  moveDown(ptr, msg.panic);
	}
      if (msg.value == 0xc2)
	{
	  moveFrwd(ptr, msg.panic);
	}
      if (msg.value == 0xc1)
	{
	  moveBack(ptr, msg.panic);
	}
      if (msg.value == 0xc8)
	{
	  moveRight(ptr, msg.panic);
	}
      if (msg.value == 0xc4)
	{
	  moveLeft(ptr, msg.panic);
	}
      if (msg.value == 0xff) // hover
	{
	  moveHover(ptr);
	}

    }
}

