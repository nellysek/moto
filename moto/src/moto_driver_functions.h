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
#define LEFT_MOTOR 6
#define RIGHT_MOTOR 3
#define FRONT_MOTOR 4
#define REAR_MOTOR 5

extern unsigned char rightPulse;
extern unsigned char leftPulse;
extern unsigned char frontPulse;
extern unsigned char rearPulse;

/*Motor pulse modification*/
void _moto_startMotors(void);
void _moto_stopMotors(void);
void _moto_goForward(void);
void _moto_goBackward(void);
void _moto_strafeRight(void);
void _moto_strafeLeft(void);

void _moto_increaseLeftNormal(void);
void _moto_increaseRightNormal(void);
void _moto_increaseFrontNormal(void);
void _moto_increaseRearNormal(void);
void _moto_increaseLeftPanic(void);
void _moto_increaseRightPanic(void);
void _moto_increaseFrontPanic(void);
void _moto_increaseRearPanic(void);

void _moto_decreaseLeftNormal(void);
void _moto_decreaseRightNormal(void);
void _moto_decreaseFrontNormal(void);
void _moto_decreaseRearNormal(void);
void _moto_decreaseLeftPanic(void);
void _moto_decreaseRightPanic(void);
void _moto_decreaseFrontPanic(void);
void _moto_decreaseRearPanic(void);

void printMotorStatus(void);
