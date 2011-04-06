/**
 * Module:       parser.c
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description:  Contains the functions that
 *               sets the pulse width of the
 *               different motors.
 *
 */

#include "header.h"
#include "motor_controls.c"
#include "tools.c"

//These definitions will go into a separate file later on.
#define STOP 0x00
#define STOP_ID 0x00
#define START 0x40
#define START_ID 0x01
#define CONTROL_ID 0x02
#define SPECIAL_COMMAND_ID 0x03
#define GO_FORWARD 0xe3 // 1110 0011
#define GO_BACKWARD 0xc3 // 1100 0011

main(void){
  int x = 5;
  
  while(x != 0){
  msg binary = scanHexMsgSTDIN();
  msg_pointer mp;
  mp = &binary;

  /* mp->ID = CONTROL; */
  /* binary.increase = 0; */
  /* binary.front = 1; */
  /* binary.rear = 1; */
  
  examineID(mp);
  printMsg(mp);
  printMotorStatus();
  x--;
  }
  return 0;

}

void examineID(msg_pointer mp){
  printf("ID is %d\n", mp->ID);

  if (mp->ID == START_ID)
    startMotors();
  if (mp->ID == STOP_ID)
    stopMotors();
  if (mp-> ID == CONTROL_ID)
    controlMotors(mp);
  if (mp-> ID == SPECIAL_COMMAND_ID)
    specialMotorCommand(mp);

  return;

}

void controlMotors(msg_pointer mp){
  printf("Standard Motor Control Message!\n");

  //Normal increase of the motors
  //i.e. panic mode not set.
  if (mp->increase == 1 && mp->panic == 0){
    if(mp->left == 1)
      increaseLeftNormal();
    if(mp->right == 1)
      increaseRightNormal();
    if(mp->front == 1)
      increaseFrontNormal();
    if(mp->rear == 1)
      increaseRearNormal();
  }
  return;

}

void specialMotorCommand(msg_pointer mp){
  printf("Special Motor Control Message!\n");

  if(BITFIELD_TO_CHAR(mp) == GO_FORWARD)
    goForward();
  if(BITFIELD_TO_CHAR(mp) == GO_BACKWARD)
    goBackward();
  
  return;

}

