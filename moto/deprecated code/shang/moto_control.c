                                                        
                                             
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
 * @description: the control of the motors functions.
 * @date 17-05-2011
 */


#include <stdio.h>
#include <stdlib.h>
#include "moto_control.h"

void initMotors(motor_ptr ptr)
{
  int i;
  motor_ptr mot;
  
  printf("initialized motors ... \n");

  // set all motors speed and pinnumber to 0
  for (i=0;i< MOTORS;i++)
    {
      mot=&ptr[i];
      mot->speed=0x0;
      mot->pinNumber= i;
    }
}

/** start motors */
void startMotors(motor_ptr ptr)
{
  motor_ptr m;
  int i,count=0;

  while (count<MOTOR_STARTTIMES) // increase the speed multiple times to start
    {
      for (i=0; i< MOTORS; i++) // loop for motors
	{
	  m = &ptr[i]; // point to motor array
	  m->speed= m->speed + SPEED_NORMAL; // increase the speed
	  setSpeed(m, m->speed); // set the speed to arduino
	}
      
      // printStatus(ptr);

      usleep(SLEEP);
      count+=1;
    }
}

/** stop motors */
void stopMotors(motor_ptr ptr)
{
  motor_ptr m;
  int i,count=0;
  for (i=0; i< MOTORS; i++)
    {
      m = &ptr[i];
      m->speed= 0;
      setSpeed(m, m->speed);
    }
}

// write to arduino or to pc
void setSpeed(motor_ptr ptr, int16_t speed)
{
#ifdef ARDUINO 
  analodWrite(ptr->pinNumber, speed);
#else
  printf("Setting speed %d to pin %x\n", speed, ptr->pinNumber);
#endif
}

/** print status of motors */
void printStatus(motor_ptr ptr) // for debugging
{
  int i;
  motor m;
  for (i=0; i< MOTORS; i++)
    {
      m = ptr[i];
      printf("Motor %d\n--------\n", i);
      printf("Pin number: %d\n", m.pinNumber);
      printf("Speed: %d\n\n", m.speed);
    }
}

/** set the speed for all motors */
void allMotors(motor_ptr ptr, int16_t speed, char increase)
{
  int i;
  motor_ptr m;
  for( i=0; i< MOTORS; i++)
    {
      m= &ptr[i];
      if (increase > 0)
	m->speed+= speed;
      else if(increase < 0)
	m->speed-= speed;
      else m->speed= speed;
      
      setSpeed(m, m->speed);
    }

}

void frontMotors(motor_ptr ptr, int16_t speed, char increase) // increase=1 : no increase, 0= increase, -1= decrease 
{
  printf("Front motors ... \n");
  motor_ptr m;

  m= &ptr[0];

  if (increase > 0) // increase mode
    m->speed+= speed; 
  else if(increase < 0) // decrease
    m->speed-= speed;
   else m->speed= speed;

  setSpeed(m, m->speed);

  m= &ptr[1];
  if (increase > 0)
    m->speed+= speed;
  else if(increase < 0)
    m->speed-= speed;
  else m->speed= speed;

  setSpeed(m, m->speed);
}

void backMotors(motor_ptr ptr, int16_t speed, char increase)
{
  printf("Back motors ... \n");
  motor_ptr m;
  m= &ptr[MOTO_REAR]; // back motor 

  if (increase > 0)
    m->speed+= speed;
  else if(increase < 0)
    m->speed-= speed;
  else m->speed= speed;


  setSpeed(m, m->speed);
  m= &ptr[MOTO_FRONT]; 

  if (increase > 0)
    m->speed+= speed;
  else if(increase < 0)
    m->speed-= speed;
  else m->speed= speed;

  setSpeed(m, m->speed);
}

void rightMotors(motor_ptr ptr, int16_t speed, char increase)
{
  printf("Right motors ... \n");
  motor_ptr m;
  m= &ptr[MOTO_RIGHT];


  if (increase > 0)
    m->speed+= speed;
  else if(increase < 0)
    m->speed-= speed;
  else m->speed= speed;

  setSpeed(m, m->speed);
  m= &ptr[MOTO_LEFT];
  if (increase > 0)
    m->speed+= speed;
  else if(increase < 0)
    m->speed-= speed;
  else m->speed= speed;


  setSpeed(m, m->speed);
}

void leftMotors(motor_ptr ptr, int16_t speed, char increase)
{
  printf("Left motors ... \n");
  motor_ptr m;
  m= &ptr[MOTO_LEFT];

  if (increase > 0)
    m->speed+= speed;
  else if(increase < 0)
    m->speed-= speed;
  else m->speed= speed;
  setSpeed(m, m->speed);

  m= &ptr[MOTO_RIGHT];
  if (increase > 0)
    m->speed+= speed;
  else if(increase < 0)
    m->speed-= speed;
  else m->speed= speed;
  setSpeed(m, m->speed);
}

/** move up */
void moveUp(motor_ptr ptr, char panic)
{
  int speed;
  if (panic == 0) speed= NORMAL_SPEED;
  else speed= PANIC_SPEED;

  allMotors(ptr, speed, 1);
}

/** move down  */
void moveDown(motor_ptr ptr, char panic)
{
  int speed;
  if (panic == 0) speed= NORMAL_SPEED;
  else speed= PANIC_SPEED;

  allMotors(ptr, speed, -1);
}
/** move right  */
void moveRight(motor_ptr ptr, char panic)
{
  int speed;
  if (panic == 0) speed= NORMAL_SPEED;
  else speed= PANIC_SPEED;

  leftMotors(ptr, speed, 1);
  rightMotors(ptr, speed, -1);
}
/** move left */
void moveLeft(motor_ptr ptr, char panic)
{
  int speed;
  if (panic == 0) speed= NORMAL_SPEED;
  else speed= PANIC_SPEED;

  leftMotors(ptr, speed, -1);
  rightMotors(ptr, speed, 1);
}
/**move forward*/
void moveFrwrd(motor_ptr ptr, char panic)
{
  int speed;
  if (panic == 0) speed= NORMAL_SPEED;
  else speed= PANIC_SPEED;

  backMotors(ptr, speed, 1);
  frontMotors(ptr, speed, -1);
}
/** move back */
void moveBack(motor_ptr ptr, char panic)
{
  int speed;
  if (panic == 0) speed= NORMAL_SPEED;
  else speed= PANIC_SPEED;

  backMotors(ptr, speed, -1);
  frontMotors(ptr, speed, 1);
}

void moveMotor(motor_ptr ptr, int motorNumber, char incrase,char panic)
{
  motor_ptr m = &ptr[motorNumber];
  int speed = m->speed;
  
  if (incrase == 1)
    {
      if (panic == 1) speed = speed+PANIC_SPEED;
      else speed = speed + NORMAL_SPEED;
    }
  else 
    {
      if (panic == 1) speed = speed - PANIC_SPEED;
      else speed= speed - NORMAL_SPEED;
    }

  setSpeed(ptr, speed);
}
