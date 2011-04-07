#define LEFT_MOTOR 2
#define RIGHT_MOTOR 3
#define FRONT_MOTOR 4
#define REAR_MOTOR 5

void startMotors();
void stopMotors();
unsigned char increaseMotorPulse(unsigned char motor, unsigned char pulse);
unsigned char increaseMotorPulsePanic(unsigned char motor, unsigned char pulse);
unsigned char decreaseMotorPulse(unsigned char motor, unsigned char pulse);
unsigned char decreaseMotorPulsePanic(unsigned char motor, unsigned char pulse);
