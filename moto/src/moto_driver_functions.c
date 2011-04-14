/**
 * Module:       motor_controls.c
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description:  Contains the functions that
 *               sets the pulse width of the
 *               different motors.
 *
 */

#ifdef ARDUINO
    #include "WProgram.h"
#elif defined PC
    #include <stdio.h>
#endif

#include "moto_driver_functions.h"

/* These are the variables keeping track of the  */
/* current state (pulse width) of each motor. */
unsigned char rightPulse;
unsigned char leftPulse;
unsigned char frontPulse;
unsigned char rearPulse;

/**
 * Function:    void _moto_startMotors()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description: Sets the pulse width to a state where
 *              all motors starts spinning but the
 *              drone does not lift off.
 *
 */
void _moto_startMotors(void){
#ifdef ARDUINO
    Serial.print("Starting all motors\n");
    leftPulse = 40;
    rightPulse = 40;
    frontPulse = 40;
    rearPulse = 40;
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
#elif defined PC
    printf("Starting all motors\n");
    leftPulse = 40;
    rightPulse = 40;
    frontPulse = 40;
    rearPulse = 40;
#endif 
}

/**
 * Function:    void _moto_stopMotors()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description: Stops all motors, i.e. sets the
 *              pulse width to zero.
 *
 */
void _moto_stopMotors(void){
#ifdef ARDUINO
    rightPulse = 0;
    leftPulse = 0;
    frontPulse = 0;
    rearPulse = 0;
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
    Serial.print("Stopping all motors\n");
#elif defined PC
    rightPulse = 0;
    leftPulse = 0;
    frontPulse = 0;
    rearPulse = 0;
    printf("Stopping all motors\n");
#endif
}

/**
 * Function:    void _moto_goForward()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description: Increases the pulse width of
 *              of the rear motor and decreases
 *              the pulse width of the front
 *              motor. This makes the drone go
 *              forward.
 *
 */
void _moto_goForward(void){
    _moto_increaseRearNormal();
    _moto_decreaseFrontNormal();
    return;

}

/**
 * Function:    void _moto_goBackward()
 * Author(s):   Kristofer Hansson Aspman
 *
 * Description: Decreases the pulse width of
 *              of the rear motor and increases
 *              the pulse width of the front
 *              motor. This makes the drone go
 *              backward.
 *
 */
void _moto_goBackward(void){
    _moto_decreaseRearNormal();
    _moto_increaseFrontNormal();
    return;
}

/**
 * Functions:   _moto_strafeRight()
 *              _moto_strafeLeft()
 *
 * Author(s):   Kristofer Hansson Aspman
 *
 * Description: Increases either right or
 *              left motor and decreases
 *              the other in order to make
 *              the drone fly sideways to
 *              either left or right.
 *              
 */
void _moto_strafeRight(void){
    _moto_decreaseRightNormal();
    _moto_increaseLeftNormal();
    return;

}
void _moto_strafeLeft(void){
    _moto_decreaseLeftNormal();
    _moto_increaseRightNormal();
    return;

}

/**
 * Functions:   _moto_increaseRightNormal()
 *              _moto_increaseLeftNormal()
 *              _moto_increaseFrontNormal()
 *              _moto_increaseRearNormal()
 *              _moto_increaseRightPanic()
 *              _moto_increaseLeftPanic()
 *              _moto_increaseFrontPanic()
 *              _moto_increaseRearPanic()
 * Author(s):   Kristofer Hansson Aspman
 *
 * Description: Increases the pulse width of
 *              the corresponding motor.
 *              Pulse width increases either
 *              by the predefined normal
 *              increment or by the predefined
 *              panic increment.
 *
 */
void _moto_increaseLeftNormal(void){
#ifdef ARDUINO 
    leftPulse += NORMAL_INCREMENT;
    analogWrite(LEFT_MOTOR, leftPulse);
#elif defined PC
    printf("Increasing left motor pulse\n");
    leftPulse += NORMAL_INCREMENT;
#endif

}

void _moto_increaseRightNormal(void){
#ifdef ARDUINO 
    rightPulse += NORMAL_INCREMENT;
    analogWrite(RIGHT_MOTOR, rightPulse);
#elif defined PC
    printf("Increasing right motor pulse\n");
    rightPulse += NORMAL_INCREMENT;
#endif
}

void _moto_increaseFrontNormal(void){
#ifdef ARDUINO
    frontPulse += NORMAL_INCREMENT;
    analogWrite(FRONT_MOTOR, frontPulse); 
#elif defined PC
    printf("Increasing Front motor pulse\n");
    frontPulse += NORMAL_INCREMENT;
#endif
}

void _moto_increaseRearNormal(void){
#ifdef ARDUINO 
    rearPulse += NORMAL_INCREMENT;
    analogWrite(REAR_MOTOR, rearPulse);
#elif defined PC
    printf("Increasing rear motor pulse\n");
    rearPulse += NORMAL_INCREMENT;
#endif
}

void _moto_increaseLeftPanic(void){
#ifdef ARDUINO 
    leftPulse += PANIC_INCREMENT;
    analogWrite(LEFT_MOTOR, leftPulse);
#elif defined PC
    printf("Increasing left motor pulse in PANIC!\n");
    leftPulse += PANIC_INCREMENT;
#endif

}

void _moto_increaseRightPanic(void){
#ifdef ARDUINO 
    rightPulse += PANIC_INCREMENT;
    analogWrite(RIGHT_MOTOR, rightPulse);
#elif defined PC
    printf("Increasing right motor pulse in PANIC!\n");
    rightPulse += PANIC_INCREMENT;
#endif
}

void _moto_increaseFrontPanic(void){
#ifdef ARDUINO 
    frontPulse += PANIC_INCREMENT;
    analogWrite(FRONT_MOTOR, frontPulse);
#elif defined PC
    printf("Increasing Front motor pulse in PANIC!\n");
    frontPulse += PANIC_INCREMENT;
#endif
}

void _moto_increaseRearPanic(void){
#ifdef ARDUINO 
    rearPulse += PANIC_INCREMENT;
    analogWrite(REAR_MOTOR, rearPulse);
#elif defined PC
    printf("Increasing rear motor pulse in PANIC!\n");
    rearPulse += PANIC_INCREMENT;
#endif
}

/**
 * Functions:   _moto_decreaseRightNormal()
 *              _moto_decreaseLeftNormal()
 *              _moto_decreaseFrontNormal()
 *              _moto_decreaseRearNormal()
 *              _moto_decreaseRightPanic()
 *              _moto_decreaseLeftPanic()
 *              _moto_decreaseFrontPanic()
 *              _moto_decreaseRearPanic()
 * Author(s):   Kristofer Hansson Aspman
 *
 * Description: Decreases the pulse width of
 *              the corresponding motor.
 *              Pulse width decreases either
 *              by the predefined normal
 *              decrement or by the predefined
 *              panic decrement.
 *
 */

void _moto_decreaseRightNormal(void){
#ifdef ARDUINO 
    rightPulse += NORMAL_DECREMENT;
    analogWrite(RIGHT_MOTOR, rightPulse);
#elif defined PC
    printf("Decreasing right motor pulse\n");
    rightPulse += NORMAL_DECREMENT;
#endif
}

void _moto_decreaseLeftNormal(void){
#ifdef ARDUINO 
    leftPulse += NORMAL_DECREMENT;
    analogWrite(LEFT_MOTOR, leftPulse);
#elif defined PC
    printf("Decreasing left motor pulse\n");
    leftPulse += NORMAL_DECREMENT;
#endif
}

void _moto_decreaseFrontNormal(void){
#ifdef ARDUINO 
    frontPulse += NORMAL_DECREMENT;
    analogWrite(FRONT_MOTOR, frontPulse);
#elif defined PC
    printf("Decreasing Front motor pulse\n");
    frontPulse += NORMAL_DECREMENT;
#endif
}

void _moto_decreaseRearNormal(void){
#ifdef ARDUINO 
    rearPulse += NORMAL_DECREMENT;
    analogWrite(REAR_MOTOR, rearPulse);
#elif defined PC
    printf("Decreasing rear motor pulse\n");
    rearPulse += NORMAL_DECREMENT;
#endif
}

void _moto_decreaseLeftPanic(void){
#ifdef ARDUINO 
    leftPulse += PANIC_DECREMENT;
    analogWrite(LEFT_MOTOR, leftPulse);
#elif defined PC
    printf("Decreasing left motor pulse in PANIC!\n");
    leftPulse += PANIC_DECREMENT;
#endif
}

void _moto_decreaseRightPanic(void){
#ifdef ARDUINO 
    rightPulse += PANIC_DECREMENT;
    analogWrite(RIGHT_MOTOR, rightPulse);
#elif defined PC
    printf("Decreasing right motor pulse in PANIC!\n");
    rightPulse += PANIC_DECREMENT;
#endif
}

void _moto_decreaseFrontPanic(void){
#ifdef ARDUINO 
    frontPulse += PANIC_DECREMENT;
    analogWrite(FRONT_MOTOR, frontPulse);
#elif defined PC
    printf("Decreasing Front motor pulse in PANIC!\n");
    frontPulse += PANIC_DECREMENT;
#endif
}

void _moto_decreaseRearPanic(void){
#ifdef ARDUINO 
    rearPulse += PANIC_DECREMENT;
    analogWrite(REAR_MOTOR, rearPulse);
#elif defined PC
    printf("Decreasing rear motor pulse in PANIC!\n");
    rearPulse += PANIC_DECREMENT;
#endif
}


/**
 * Function:     printMotorStatus()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description:  Prints out the status of the
 *               motors to either the terminal
 *               or the serial monitor depending
 *               on whether the ARDUINO or PC
 *               flags are set.
 *
 */

void printMotorStatus(void){
#ifdef ARDUINO 
    //Arduino code begin
    Serial.println("****************************");
    Serial.println("Current status of the motors");
    Serial.print("Right:  ");
    Serial.println(rightPulse, DEC);
    Serial.print("Left:  ");
    Serial.println(leftPulse, DEC);
    Serial.print("Front:  ");
    Serial.println(frontPulse, DEC);
    Serial.print("Rear:  ");
    Serial.println(rearPulse, DEC);
    Serial.println("****************************");
    //Arduino code end
#elif defined PC
    //PC code begin
    printf("****************************\n");
    printf("Current status of the motors\n\n");
    printf("Left:  %d   Right: %d\n", leftPulse, rightPulse);
    printf("Front: %d   Rear:  %d\n", frontPulse, rearPulse);
    printf("****************************\n");
    //PC code end
#endif
}
