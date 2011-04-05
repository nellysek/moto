#include "motorcontrol.c"

unsigned char startMotors();

unsigned char stopMotors();

unsigned char increaseMotorPulse(unsigned char motor, unsigned char pulse);

unsigned char increaseMotorPulsePanic(unsigned char motor, unsigned char pulse);

unsigned char decreaseMotorPulse(unsigned char motor, unsigned char pulse);

unsigned char decreaseMotorPulsePanic(unsigned char motor, unsigned char pulse);

