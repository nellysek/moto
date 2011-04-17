/**
 * Module:       motor_controls.c
 * Author(s):    Björn Eriksson & Magnus Bergqvist
 *
 * Description:  Contains the functions that
 *               sets the pulse width of the
 *               different motors.
 *
 * Include "motorcontrol.h" for marcors and static variables, 
 *         "WProgram.h" for the lib arduino
 */



#include "motorcontrol.h"

#ifdef ARDUINO
    #include "WProgram.h"
#elif defined PC 
    #include <stdio.h>
#endif

unsigned char leftPulse = 0;
unsigned char rightPulse = 0;
unsigned char frontPulse = 0;
unsigned char rearPulse = 0;


/**
 * Function:    void startMotors()
 * Description: sets the pulse to 62
 *              (will probably change when the hardware comes),
 *              the propellers starts moving without the drone lifts off.
 */



void startMotors() 
{
    leftPulse = 62;
    rightPulse = 62;
    frontPulse = 62;
    rearPulse = 62;
#ifdef ARDUINO /*Arduino code for sending the pulse to motors*/
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
#elif defined PC /* PC code */
    printf("Left motor: %d, right motor: %d,", 
            "front motor: %d, rear motor: %d \n",
            leftPulse, rightPulse, frontPulse, rearPulse);
#endif
}

/**
 * Function:    void stopMotors()
 * Description: stops all the four motors by setting the pulse to zero 
 */

void stopMotors() 
{
    leftPulse = 0;
    rightPulse = 0;
    frontPulse = 0;
    rearPulse = 0;
#ifdef ARDUINO /*Arduino code for sending the pulse to motors*/
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
#elif defined PC /* PC code */
    printf("Left motor: %d, right motor: %d", 
            "front motor: %d, rear motor: %d \n",
            leftPulse, rightPulse, frontPulse, rearPulse);
#endif
}

/**
 * Function:    unsigned char increaseMotorPulse()
 * Description: increase the pulse by a fixed number (3), max value is 255 
 *
 * Return:      the new pulse value.
 */

unsigned char increaseMotorPulse(unsigned char motor, unsigned char pulse) 
{
    if(pulse < 252) 
    {
        pulse = pulse + 3;
#ifdef ARDUINO /*Arduino code for sending the pulse to motors*/
        analogWrite(motor, pulse);
#elif defined PC /* PC code */
    printf("Motor: %d, Pulse: %d", motor, pulse);
#endif
        return pulse;
    }
    return 255;
}
/**
 * Function:    unsigned char increaseMotorPulseX2()
 * Description: increase the pulse by the double amount as the normal increase 
 *
 * Return:      the new pulse value.
 */

unsigned char increaseMotorPulseX2(unsigned char motor, unsigned char pulse) 
{
    if(pulse < 249) 
    {
        pulse = pulse + 6;
#ifdef ARDUINO /*Arduino code for sending the pulse to motors*/
        analogWrite(motor, pulse);
#elif defined PC /* PC code */
    printf("Motor: %d, Pulse: %d", motor, pulse);
#endif
        return pulse;
    }
    return 255;
}

/**
 * Function:    unsigned char decreaseMotorPulse()
 * Description: decrease the pulse by a fixed number (3), min value is 3 
 *
 * Return:      the new pulse value.
 */

unsigned char decreaseMotorPulse(unsigned char motor, unsigned char pulse) 
{
    if(pulse > 3) 
    {
        pulse = pulse - 3;
#ifdef ARDUINO /*Arduino code for sending the pulse to motors*/
        analogWrite(motor, pulse);
#elif defined PC /* PC code */
    printf("Motor: %d, Pulse: %d", motor, pulse);
#endif
        return pulse;
    }	
    return 3;
}

/**
 * Function:    unsigned char decreaseMotorPulseX2()
 * Description: decrease the pulse by the double amount as the normal decrease 
 *
 * Return:      the new pulse value.
 */

unsigned char decreaseMotorPulseX2(unsigned char motor, unsigned char pulse)
{
    if(pulse > 6) 
    {
        pulse = pulse - 6;
#ifdef ARDUINO /*Arduino code for sending the pulse to motors*/
        analogWrite(motor, pulse);
#elif defined PC /* PC code */
    printf("Motor: %d, Pulse: %d", motor, pulse);
#endif
        return pulse;
    }	
    return 3;
}
		
