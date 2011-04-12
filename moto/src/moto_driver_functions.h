/**
 * Module:       motor_control.h
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description:  The typedef of the bitfield struct and
 *               all the prototypes for the functions used
 *               by tools.c, motor_control.c and parser.c.
 *
 */

#ifdef ARDUINO
   #include "WProgram.h"
#elif defined PC
   #include <stdio.h>
#endif

#define NORMAL_INCREMENT 2
#define PANIC_INCREMENT 4
#define NORMAL_DECREMENT -2
#define PANIC_DECREMENT -4


extern unsigned char rightMotor;
extern unsigned char leftMotor;
extern unsigned char frontMotor;
extern unsigned char rearMotor;

/*Motor pulse modification*/
void startMotors(void);
void stopMotors(void);
void goForward(void);
void goBackward(void);
void increaseLeftNormal(void);
void increaseRightNormal(void);
void increaseFrontNormal(void);
void increaseRearNormal(void);
void increaseLeftPanic(void);
void increaseRightPanic(void);
void increaseFrontPanic(void);
void increaseRearPanic(void);

void decreaseLeftNormal(void);
void decreaseRightNormal(void);
void decreaseFrontNormal(void);
void decreaseRearNormal(void);
void decreaseLeftPanic(void);
void decreaseRightPanic(void);
void decreaseFrontPanic(void);
void decreaseRearPanic(void);

void printMotorStatus(void);