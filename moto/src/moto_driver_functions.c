/** 
 * Module:       motor_controls.c
 * Author(s):    Kristofer Hansson Aspman,
 *               Björn Eriksson
 *               Magnus Bergqvist
 *
 * Description:  Contains the functions that
 *               sets the pulse width of the
 *               different motors.
 *
 */
 
 #ifdef ARDUINO_DBG
<<<<<<< .merge_file_pZTNg8
	#define ARDUNO
=======
	#define ARDUINO
>>>>>>> .merge_file_4BJ4Z7
#endif

#ifdef ARDUINO
    #include "WProgram.h"
#elif defined PC
    #include <stdio.h>
    #include"../test/cunit_stubs.h"
#endif

/* 
 * A printout test inspired by Henrik Sandklef.
 * The defined names ending with a number specifies the
 * number of arguments each macro takes, i.e. the number
 * of arguments that is to be sent to the printout
 */
#ifdef ARDUINO_DBG
    #define PRINTOUT_1(a) Serial.print(a)
    #define PRINTOUT_2(a, b) Serial.print(a, b)
    #define PRINTOUT_3(a, b, c) Serial.print(a, b, c)
#elif defined PC
    #define PRINTOUT_1(a) printf(a)
    #define PRINTOUT_2(a, b) printf(a, b)
    #define PRINTOUT_3(a, b, c) printf(a, b, c)
#endif

#include "moto_driver_functions.h"
#include <stdint.h>

/* These are the variables keeping track of the  */
/* current state (pulse width) of each motor. */
uint16_t rightPulse;
uint16_t leftPulse;
uint16_t frontPulse;
uint16_t rearPulse;

/**
 * Function:    void moto_startMotors()
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *
 * Description: Sets the pulse width to a state where
 *              all motors starts spinning but the
 *              drone does not lift off.
 *
 */
void moto_startMotors(void){
<<<<<<< .merge_file_pZTNg8
    leftPulse = 40;
    rightPulse = 40;
    frontPulse = 40;
    rearPulse = 40;
#ifdef ARDUINO_DBG
    Serial.print("Starting all motors\n");
#elif defined PC
    printf("Starting all motors\n");
#endif 

#ifdef ARDUINO
=======
    leftPulse = IDLE_SPEED;
    rightPulse = IDLE_SPEED;
    frontPulse = IDLE_SPEED;
    rearPulse = IDLE_SPEED;
>>>>>>> .merge_file_4BJ4Z7
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
<<<<<<< .merge_file_pZTNg8
#endif
=======

    PRINTOUT_1("Starting all motors\n");
>>>>>>> .merge_file_4BJ4Z7
}

/**
 * Function:    void moto_stopMotors()
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *
 * Description: Stops all motors, i.e. sets the
 *              pulse width to zero.
 *
 */
void moto_stopMotors(void){
<<<<<<< .merge_file_pZTNg8
    rightPulse = 0;
    leftPulse = 0;
    frontPulse = 0;
    rearPulse = 0;
#ifdef ARDUINO_BDG
    Serial.print("Stopping all motors\n");
#elif defined PC
    printf("Stopping all motors\n");
#endif

#ifdef ARDUINO
analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
#endif
=======
    rightPulse = STOP_PULSE;
    leftPulse = STOP_PULSE;
    frontPulse = STOP_PULSE;
    rearPulse = STOP_PULSE;
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
    
    PRINTOUT_1("Stopping all motors\n");
>>>>>>> .merge_file_4BJ4Z7
}
/**
 * Function:    void moto_hover()
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *
 * Description: Sets all motors to the same pulse width
 *              where to drone shall stay in hover state
 *
 */
void moto_hover(void){
<<<<<<< .merge_file_pZTNg8
    rightPulse =90;
    leftPulse = 90;
    frontPulse = 90;
    rearPulse = 90;

#ifdef ARDUINO
=======
    rightPulse =1200;
    leftPulse = 1200;
    frontPulse = 1200;
    rearPulse = 1200;
>>>>>>> .merge_file_4BJ4Z7
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);

    PRINTOUT_1("Hovering\n");    
}




/**
 * Function:    void moto_goForward()
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *
 * Description: Increases the pulse width of
 *              of the rear motor and decreases
 *              the pulse width of the front
 *              motor. This makes the drone go
 *              forward.
 *
 */
void moto_goForward(void){
    moto_increaseRearNormal();
    moto_decreaseFrontNormal();
    return;

}

/**
 * Function:    void moto_goBackward()
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *
 * Description: Decreases the pulse width of
 *              of the rear motor and increases
 *              the pulse width of the front
 *              motor. This makes the drone go
 *              backward.
 *
 */
void moto_goBackward(void){
    moto_decreaseRearNormal();
    moto_increaseFrontNormal();
    return;
}

/**
 * Functions:   moto_strafeRight()
 *              moto_strafeLeft()
 *
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *
 * Description: Increases either right or
 *              left motor and decreases
 *              the other in order to make
 *              the drone fly sideways to
 *              either left or right.
 *              
 */
void moto_strafeRight(void){
    moto_decreaseRightNormal();
    moto_increaseLeftNormal();
    return;
}

void moto_strafeLeft(void){
    moto_decreaseLeftNormal();
    moto_increaseRightNormal();
    return;
}

/**
 * Functions:   moto_rotateLeft()
 *              moto_rotateRight()
 *
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *
 * Description: Increases either right and
 *              left or front and rear
*               motor and decreases
 *              the other in order to make
 *              the drone turn either righ or left.
 *              
 */

void moto_rotateLeft(void){
    moto_increaseLeftNormal();
    moto_increaseRightNormal();
    moto_decreaseFrontNormal();
    moto_decreaseRearNormal();
    return;
}

void moto_rotateRight(void){
    moto_decreaseLeftNormal();
    moto_decreaseRightNormal();
    moto_increaseFrontNormal();
    moto_increaseRearNormal();
    return;
}
/**
 * Functions:   moto_increaseAll()
 *              moto_increaseAllPanic()
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *              Magnus Bergqvist
 *
 * Description: Increases the pulse width of
 *              all the motors.
 *              Pulse width increases either
 *              by the predefined normal
 *              increment or by the predefined
 *              panic increment.
 *
 */

void moto_increaseAllNormal(void){
<<<<<<< .merge_file_pZTNg8
    rightPulse += NORMAL_INCREMENT;
    leftPulse += NORMAL_INCREMENT;
    frontPulse += NORMAL_INCREMENT;
    rearPulse += NORMAL_INCREMENT;

#ifdef ARDUINO
=======
    rightPulse = rightMotorLimitIncrease(rightPulse, NORMAL_STEP);
    leftPulse = leftMotorLimitIncrease(leftPulse, NORMAL_STEP);
    frontPulse = frontMotorLimitIncrease(frontPulse, NORMAL_STEP);
    rearPulse = rearMotorLimitIncrease(rearPulse, NORMAL_STEP);
>>>>>>> .merge_file_4BJ4Z7
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);

    PRINTOUT_1("increases all motors\n");
}

void moto_increaseAllPanic(void){
<<<<<<< .merge_file_pZTNg8
    rightPulse += PANIC_INCREMENT;
    leftPulse += PANIC_INCREMENT;
    frontPulse += PANIC_INCREMENT;
    rearPulse += PANIC_INCREMENT;

#ifdef ARDUINO
=======
    rightPulse = rightMotorLimitIncrease(rightPulse, PANIC_STEP);
    leftPulse = leftMotorLimitIncrease(leftPulse, PANIC_STEP);
    frontPulse = frontMotorLimitIncrease(frontPulse, PANIC_STEP);
    rearPulse = rearMotorLimitIncrease(rearPulse, PANIC_STEP);
>>>>>>> .merge_file_4BJ4Z7
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);

    PRINTOUT_1("increases all motors\n");
}
/**
 * Functions:   moto_decreaseAll()
 *              moto_decreaseAllPanic()
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *              Magnus Bergqvist
 *
 * Description: Decreases the pulse width of
 *              all the motors.
 *              Pulse width decreases either
 *              by the predefined normal
 *              decrement or by the predefined
 *              panic decrement.
 *
 */

void moto_decreaseAllNormal(void){
<<<<<<< .merge_file_pZTNg8
    rightPulse += NORMAL_DECREMENT;
    leftPulse += NORMAL_DECREMENT;
    frontPulse += NORMAL_DECREMENT;
    rearPulse += NORMAL_DECREMENT;

#ifdef ARDUINO
=======
    rightPulse = rightMotorLimitDecrease(rightPulse, NORMAL_STEP);
    leftPulse = leftMotorLimitDecrease(leftPulse, NORMAL_STEP);
    frontPulse = frontMotorLimitDecrease(frontPulse, NORMAL_STEP);
    rearPulse = rearMotorLimitDecrease(rearPulse, NORMAL_STEP);
>>>>>>> .merge_file_4BJ4Z7
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);

    PRINTOUT_1("decreases all motors\n");
}

void moto_decreaseAllPanic(void){
<<<<<<< .merge_file_pZTNg8
    rightPulse += PANIC_DECREMENT;
    leftPulse += PANIC_DECREMENT;
    frontPulse += PANIC_DECREMENT;
    rearPulse += PANIC_DECREMENT;

#ifdef ARDUINO
=======
    rightPulse = rightMotorLimitDecrease(rightPulse, PANIC_STEP);
    leftPulse = leftMotorLimitDecrease(leftPulse, PANIC_STEP);
    frontPulse = frontMotorLimitDecrease(frontPulse, PANIC_STEP);
    rearPulse = rearMotorLimitDecrease(rearPulse, PANIC_STEP);
>>>>>>> .merge_file_4BJ4Z7
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);

    PRINTOUT_1("decreases all motors\n");
}
/**
 * Functions:   moto_increaseRightNormal()
 *              moto_increaseLeftNormal()
 *              moto_increaseFrontNormal()
 *              moto_increaseRearNormal()
 *              moto_increaseRightPanic()
 *              moto_increaseLeftPanic()
 *              moto_increaseFrontPanic()
 *              moto_increaseRearPanic()
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *
 * Description: Increases the pulse width of
 *              the corresponding motor.
 *              Pulse width increases either
 *              by the predefined normal
 *              increment or by the predefined
 *              panic increment. Every motor
 *              can have individual max & min
 *              levels due to HW tolerances
 *              
 */
    
void moto_increaseLeftNormal(void){
<<<<<<< .merge_file_pZTNg8
    leftPulse += NORMAL_INCREMENT;

#ifdef ARDUINO 
=======
    leftPulse = leftMotorLimitIncrease(leftPulse, NORMAL_STEP);
>>>>>>> .merge_file_4BJ4Z7
    analogWrite(LEFT_MOTOR, leftPulse);

    PRINTOUT_1("Increasing left motor pulse\n");
}

void moto_increaseRightNormal(void){
    rightPulse = rightMotorLimitIncrease(rightPulse, NORMAL_STEP);
    analogWrite(RIGHT_MOTOR, rightPulse);

    PRINTOUT_1("Increasing right motor pulse\n");
}

void moto_increaseFrontNormal(void){
    frontPulse = frontMotorLimitIncrease(frontPulse, NORMAL_STEP);
    analogWrite(FRONT_MOTOR, frontPulse);

    PRINTOUT_1("Increasing Front motor pulse\n");
}

void moto_increaseRearNormal(void){
    rearPulse = rearMotorLimitIncrease(rearPulse, NORMAL_STEP);
    analogWrite(REAR_MOTOR, rearPulse);

    PRINTOUT_1("Increasing rear motor pulse\n");
}

void moto_increaseLeftPanic(void){
    leftPulse = leftMotorLimitIncrease(leftPulse, PANIC_STEP);
    analogWrite(LEFT_MOTOR, leftPulse);

    PRINTOUT_1("Increasing left motor pulse in PANIC!\n");
}

void moto_increaseRightPanic(void){
    rightPulse = rightMotorLimitIncrease(rightPulse, PANIC_STEP);
    analogWrite(RIGHT_MOTOR, rightPulse);

    PRINTOUT_1("Increasing right motor pulse in PANIC!\n");
}

void moto_increaseFrontPanic(void){
    frontPulse = frontMotorLimitIncrease(frontPulse, PANIC_STEP);
    analogWrite(FRONT_MOTOR, frontPulse);

    PRINTOUT_1("Increasing Front motor pulse in PANIC!\n");
}

void moto_increaseRearPanic(void){
    rearPulse = rearMotorLimitIncrease(rearPulse, PANIC_STEP);
    analogWrite(REAR_MOTOR, rearPulse);

    PRINTOUT_1("Increasing rear motor pulse in PANIC!\n");
}

/**
 * Functions:   moto_decreaseRightNormal()
 *              moto_decreaseLeftNormal()
 *              moto_decreaseFrontNormal()
 *              moto_decreaseRearNormal()
 *              moto_decreaseRightPanic()
 *              moto_decreaseLeftPanic()
 *              moto_decreaseFrontPanic()
 *              moto_decreaseRearPanic()
 * Author(s):   Kristofer Hansson Aspman,
 *              Björn Eriksson
 *
 * Description: Decreases the pulse width of
 *              the corresponding motor.
 *              Pulse width decreases either
 *              by the predefined normal
 *              decrement or by the predefined
 *              panic decrement.
 *
 */

void moto_decreaseRightNormal(void){
    rightPulse = rightMotorLimitDecrease(rightPulse, NORMAL_STEP);
    analogWrite(RIGHT_MOTOR, rightPulse);

    PRINTOUT_1("Decreasing right motor pulse\n");
}

void moto_decreaseLeftNormal(void){
    leftPulse = leftMotorLimitDecrease(leftPulse, NORMAL_STEP);
    analogWrite(LEFT_MOTOR, leftPulse);

    PRINTOUT_1("Decreasing left motor pulse\n");
}

void moto_decreaseFrontNormal(void){
    frontPulse = frontMotorLimitDecrease(frontPulse, NORMAL_STEP);
    analogWrite(FRONT_MOTOR, frontPulse);

    PRINTOUT_1("Decreasing Front motor pulse\n");
}

void moto_decreaseRearNormal(void){
    rearPulse = rearMotorLimitDecrease(rearPulse, NORMAL_STEP);
    analogWrite(REAR_MOTOR, rearPulse);

    PRINTOUT_1("Decreasing rear motor pulse\n");
}

void moto_decreaseLeftPanic(void){
    leftPulse = leftMotorLimitDecrease(leftPulse, PANIC_STEP);
    analogWrite(LEFT_MOTOR, leftPulse);

    PRINTOUT_1("Decreasing left motor pulse in PANIC!\n");
}

void moto_decreaseRightPanic(void){
    rightPulse = rightMotorLimitDecrease(rightPulse, PANIC_STEP);
    analogWrite(RIGHT_MOTOR, rightPulse);

    PRINTOUT_1("Decreasing right motor pulse in PANIC!\n");
}

void moto_decreaseFrontPanic(void){
    frontPulse = frontMotorLimitDecrease(frontPulse, PANIC_STEP);
    analogWrite(FRONT_MOTOR, frontPulse);

    PRINTOUT_1("Decreasing Front motor pulse in PANIC!\n");
}

void moto_decreaseRearPanic(void){
    rearPulse = rearMotorLimitDecrease(rearPulse, PANIC_STEP);
    analogWrite(REAR_MOTOR, rearPulse);

    PRINTOUT_1("Decreasing rear motor pulse in PANIC!\n");
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
#ifdef ARDUINO_DBG
    /* Arduino code begin*/
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
    /* Arduino code end */
#elif defined PC
    /* PC code begin */
    printf("****************************\n");
    printf("Current status of the motors\n\n");
    printf("Left:  %d   Right: %d\n", leftPulse, rightPulse);
    printf("Front: %d   Rear:  %d\n", frontPulse, rearPulse);
    printf("****************************\n");
    /* PC code end */
#endif
}

void sendMsg(void){
    struct pulses currentPulse = 
    {rightPulse, leftPulse, frontPulse, rearPulse};
    /* send(currentPulse);  not sure how the send funcrion till look like */
}

<<<<<<< .merge_file_pZTNg8
=======
/**
 * Functions:    rightMotorLimitIncrease()
 *               rightMotorLimitDecrease()
 *               leftMotorLimitIncrease()
 *               leftMotorLimitDecrease()
 *               frontMotorLimitIncrease()
 *               frontMotorLimitDecrease()
 *               rearMotorLimitIncrease()
 *               rearMotorLimitDecrease()
 * Author(s):    Magnus Bergqvist
 *
 * Description:  Functions contains the logic
 *               that determines and returns
 *               a valid input value to the motors.
 *               Returned values are calibrated for
 *               the functions corresponding motor.
 */
 
uint16_t rightMotorLimitIncrease(uint16_t currentPulse,
                                        uint16_t increment){
    if((currentPulse + increment) < MAX_PULSE_RIGHT){
        return (currentPulse + increment);
    }
    else{
        return MAX_PULSE_RIGHT;
    }
}

uint16_t rightMotorLimitDecrease(uint16_t currentPulse,
                                        uint16_t decrement){
    if((currentPulse - decrement) > MIN_PULSE_RIGHT){
        return (currentPulse - decrement);
    }
    else{
        return MIN_PULSE_RIGHT;
    }
}

uint16_t leftMotorLimitIncrease(uint16_t currentPulse,
                                        uint16_t increment){
    if((currentPulse + increment) < MAX_PULSE_LEFT){
        return (currentPulse + increment);
    }
    else{
        return MAX_PULSE_LEFT;
    }
}

uint16_t leftMotorLimitDecrease(uint16_t currentPulse,
                                        uint16_t decrement){
    if((currentPulse - decrement) > MIN_PULSE_LEFT){
        return (currentPulse - decrement);
    }
    else{
        return MIN_PULSE_LEFT;
    }
}

uint16_t frontMotorLimitIncrease(uint16_t currentPulse,
                                        uint16_t increment){
    if((currentPulse + increment) < MAX_PULSE_FRONT){
        return (currentPulse + increment);
    }
    else{
        return MAX_PULSE_FRONT;
    }
}

uint16_t frontMotorLimitDecrease(uint16_t currentPulse,
                                        uint16_t decrement){
    if((currentPulse - decrement) > MIN_PULSE_FRONT){
        return (currentPulse - decrement);
    }
    else{
        return MIN_PULSE_FRONT;
    }
}

uint16_t rearMotorLimitIncrease(uint16_t currentPulse,
                                        uint16_t increment){
    if((currentPulse + increment) < MAX_PULSE_REAR){
        return (currentPulse + increment);
    }
    else{
        return MAX_PULSE_REAR;
    }
}

uint16_t rearMotorLimitDecrease(uint16_t currentPulse,
                                        uint16_t decrement){
    if((currentPulse - decrement) > MIN_PULSE_REAR){
        return (currentPulse - decrement);
    }
    else{
        return MIN_PULSE_REAR;
    }
}
>>>>>>> .merge_file_4BJ4Z7
