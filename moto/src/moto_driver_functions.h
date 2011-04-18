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
/* defines which "pin" in the arduino, to be changed further on */
#define LEFT_MOTOR 6
#define RIGHT_MOTOR 3
#define FRONT_MOTOR 4
#define REAR_MOTOR 5

extern unsigned char rightPulse;
extern unsigned char leftPulse;
extern unsigned char frontPulse;
extern unsigned char rearPulse;

/*Motor pulse modification*/
void moto_startMotors(void);
void moto_stopMotors(void);
void moto_goForward(void);
void moto_goBackward(void);
void moto_strafeRight(void);
void moto_strafeLeft(void);

void moto_increaseAllNormal(void);
void moto_increaseAllPanic(void);

void moto_decreaseAllNormal(void);
void moto_decreaseAllPanic(void);

void moto_increaseLeftNormal(void);
void moto_increaseRightNormal(void);
void moto_increaseFrontNormal(void);
void moto_increaseRearNormal(void);
void moto_increaseLeftPanic(void);
void moto_increaseRightPanic(void);
void moto_increaseFrontPanic(void);
void moto_increaseRearPanic(void);

void moto_decreaseLeftNormal(void);
void moto_decreaseRightNormal(void);
void moto_decreaseFrontNormal(void);
void moto_decreaseRearNormal(void);
void moto_decreaseLeftPanic(void);
void moto_decreaseRightPanic(void);
void moto_decreaseFrontPanic(void);
void moto_decreaseRearPanic(void);

void printMotorStatus(void);

/* Just to get som kind of f*cking structure, functions to be discussed */
unsigned char rightMotorCalibIncrease(unsigned char currentPulse,
                                        unsigned char increment);
unsigned char rightMotorCalibDecrease(unsigned char currentPulse,
                                        unsigned char decrement);
unsigned char leftMotorCalibIncrease(unsigned char currentPulse,
                                        unsigned char increment);
unsigned char leftMotorCalibDecrease(unsigned char currentPulse,
                                        unsigned char decrement);
unsigned char frontMotorCalibIncrease(unsigned char currentPulse,
                                        unsigned char increment);
unsigned char frontMotorCalibDecrease(unsigned char currentPulse,
                                        unsigned char decrement);
unsigned char rearMotorCalibIncrease(unsigned char currentPulse,
                                        unsigned char increment);
unsigned char rearMotorCalibDecrease(unsigned char currentPulse,
                                        unsigned char decrement);
                                                                                
