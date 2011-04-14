/**
 * Header:       motorcontrol.h
 * Author(s):    Björn Eriksson & Magnus Bergqvist
 *
 * Description:  Defines the different motors as macros and 
 *               declares all the functions.
 *
 */


#define LEFT_MOTOR 6
#define RIGHT_MOTOR 3
#define FRONT_MOTOR 4
#define REAR_MOTOR 5

void startMotors();
void stopMotors();
unsigned char increaseMotorPulse(unsigned char motor, unsigned char pulse);
unsigned char increaseMotorPulseX2(unsigned char motor, unsigned char pulse);
unsigned char decreaseMotorPulse(unsigned char motor, unsigned char pulse);
unsigned char decreaseMotorPulseX2(unsigned char motor, unsigned char pulse);
