/**
 * Module:       header.h
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description:  The typedef of the bitfield struct and
 *               all the prototypes for the functions used
 *               by tools.c, motor_control.c and parser.c.
 *
 */

#include <stdio.h>

//Big endian control message
typedef struct control_message{
  //unsigned char may not be portable
  //if that is the case, try just unsigned
  //also, endianess may be different on arduino
  unsigned char rear :1;
  unsigned char front :1;
  unsigned char right :1;
  unsigned char left :1;
  unsigned char panic :1;
  unsigned char increase :1;
  unsigned char ID :2;
} msg, *msg_pointer;

//Little endian control message
/* struct control_message{ */
/*   unsigned char ID :2; */
/*   unsigned char increase :1; */
/*   unsigned char panic :1; */
/*   unsigned char left :1; */
/*   unsigned char right :1; */
/*   unsigned char front :1; */
/*   unsigned char rear :1; */

/* } msg; */


//Tools
unsigned char bitfieldToChar(msg_pointer mp);
msg intToBitfield(unsigned int* ip);
void printMsg(msg_pointer mp);
msg scanDecMsgSTDIN();
msg scanHexMsgSTDIN();
void printMotorStatus();

//Parser functions
void examineID(msg_pointer mp);
void controlMotors(msg_pointer mp);
void specialMotorCommand(msg_pointer mp);

//Motor pulse modification
void startMotors();
void stopMotors();
void goForward();
void goBackward();
void increaseLeftNormal();
void increaseRightNormal();
void increaseFrontNormal();
void increaseRearNormal();
void increaseLeftPanic();
void increaseRightPanic();
void increaseFrontPanic();
void increaseRearPanic();
