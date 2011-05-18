/*!
 * @author Kristofer Hansson Aspman \n
 *         Björn Eriksson \n
 *         Magnus Bergqvist        
 * @file moto_driver_functions.c
 * @version v0.03
 * @date 2011-05-09
 * @brief Contains the functions that sets the pulse width of the \n
          different motors.
 * @history 2011-05-17: Implemented moto_map() function \n
                        (Magnus) \n
            2011-05-09: Added map function and moved printout macros \n
                        to moto_printer_functions, changed the printouts \n
                        to fully comply with the new macro style \n
                        (Magnus) \n
            2011-04-03: Created the file. \n 
                        (Kristofer)
 */
 
#include "moto_driver_functions.h"
#include <stdint.h>
#include <math.h>
#include "moto_interface.h"
#include "moto_printer_functions.h"

#ifdef ARDUINO
    #include "WProgram.h"
    #include "../include/Servo.h"
#elif defined PC
    #include"moto_stubs.h"
#endif

/* 
 * These are the variables keeping track of the current state (pulse width)
 * of each motor, before the value is mapped. 
 */
uint16_t rightPulse;
uint16_t leftPulse;
uint16_t frontPulse;
uint16_t rearPulse;

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson \n
           Magnus Bergqvist
 * @function moto_startMotors
 * @param void
 * @return void
 * @brief moto_startMotors sets the pulse width to a level where all motors \n
          starts spinning but the drone does not lift off.
 */
void moto_startMotors(void){
    leftPulse = IDLE_SPEED;
    rightPulse = IDLE_SPEED;
    frontPulse = IDLE_SPEED;
    rearPulse = IDLE_SPEED;
#ifdef ARDUINO 
    escRight.writeMicroseconds(rightPulse);
    escLeft.writeMicroseconds(leftPulse);
    escFront.writeMicroseconds(frontPulse);
    escRear.writeMicroseconds(rearPulse);
#elif defined PC
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
#endif
    PRINT_STRING("Starting all motors");
    PRINT_NEW_LINE;
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson \n
           Magnus Bergqvist
 * @function moto_stopMotors
 * @param void
 * @return void
 * @brief moto_stopMotors stops all motors, i.e. sets the pulse width to a \n
          value where all the motors stops turning.
 */
void moto_stopMotors(void){
    rightPulse = STOP_PULSE;
    leftPulse = STOP_PULSE;
    frontPulse = STOP_PULSE;
    rearPulse = STOP_PULSE;
#ifdef ARDUINO 
    escRight.writeMicroseconds(rightPulse);
    escLeft.writeMicroseconds(leftPulse);
    escFront.writeMicroseconds(frontPulse);
    escRear.writeMicroseconds(rearPulse);
#elif defined PC
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
#endif
    PRINT_STRING("Stopping all motors");
    PRINT_NEW_LINE;
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson \n
           Magnus Bergqvist
 * @function moto_hover
 * @param void
 * @return void
 * @brief moto_hover sets all motors to the same pulse width where the \n
          drone shall stay in some kind of hover state. Can be used to get \n
          a known state of all the engines to make calculations for \n
          stability from.
 */

void moto_hover(void){
    rightPulse = HOVER_PULSE_RIGHT;
    leftPulse = HOVER_PULSE_LEFT;
    frontPulse = HOVER_PULSE_FRONT;
    rearPulse = HOVER_PULSE_REAR;
#ifdef ARDUINO 
    escRight.writeMicroseconds(rightPulse);
    escLeft.writeMicroseconds(leftPulse);
    escFront.writeMicroseconds(frontPulse);
    escRear.writeMicroseconds(rearPulse);
#elif defined PC
    analogWrite(RIGHT_MOTOR, rightPulse);
    analogWrite(LEFT_MOTOR, leftPulse);
    analogWrite(FRONT_MOTOR, frontPulse);
    analogWrite(REAR_MOTOR, rearPulse);
#endif
    PRINT_STRING("Hovering");
    PRINT_NEW_LINE;    
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson
 * @function moto_goForward
 * @param void
 * @return void
 * @brief Increases the pulse width of the rear motor and decreases the \n
          pulse width of the front motor. This makes the drone go forward. 
 */
void moto_goForward(void){
    moto_increaseRearNormal();
    moto_decreaseFrontNormal();
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson
 * @function moto_goForwardPanic
 * @param void
 * @return void
 * @brief Increases the pulse width of the rear motor and decreases the \n
          pulse width of the front motor with larger steps. \n
          This makes the drone go forward.
 */
void moto_goForwardPanic(void){
    moto_increaseRearPanic();
    moto_decreaseFrontPanic();
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson
 * @function moto_goBackward
 * @param void
 * @return void
 * @brief Decreases the pulse width of the rear motor and increases the \n
          pulse width of the front motor. This makes the drone go backward.
 */
void moto_goBackward(void){
    moto_decreaseRearNormal();
    moto_increaseFrontNormal();
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson
 * @function moto_goBackwardPanic
 * @param void
 * @return void
 * @brief Decreases the pulse width of the rear motor and increases the \n
          pulse width of the front motor with larger steps. \n
          This makes the drone go backward.
 */
void moto_goBackwardPanic(void){
    moto_decreaseRearPanic();
    moto_increaseFrontPanic();
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson
 * @function moto_strafeRight
 * @param void
 * @return void
 * @brief Decreases the right motor and increases the left, this makes the \n
          drone move sideways to the right.
 */
void moto_strafeRight(void){
    moto_decreaseRightNormal();
    moto_increaseLeftNormal();
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson
 * @function moto_strafeLeft
 * @param void
 * @return void
 * @brief Decreases the left motor and increases the right, this makes the \n
          drone move sideways to the left.
 */
void moto_strafeLeft(void){
    moto_decreaseLeftNormal();
    moto_increaseRightNormal();
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson
 * @function moto_rotateLeft()
 * @param void
 * @return void
 * @brief Increases left and right motors and decreases front and rear. \n
          this makes the drone rotate left.
 */
void moto_rotateLeft(void){
    moto_increaseLeftNormal();
    moto_increaseRightNormal();
    moto_decreaseFrontNormal();
    moto_decreaseRearNormal();
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson
 * @function moto_rotateRight()
 * @param void
 * @return void
 * @brief Increases front and rear motors and decreases left and right. \n
          this makes the drone rotate right.
 */
void moto_rotateRight(void){
    moto_decreaseLeftNormal();
    moto_decreaseRightNormal();
    moto_increaseFrontNormal();
    moto_increaseRearNormal();
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson \n
           Magnus Bergqvist
 * @function moto_increaseAllNormal()
 * @param void
 * @return void
 * @brief Increases the pulse width of all the motors. Pulse width \n
          increases by a predefined normal step.
 */
void moto_increaseAllNormal(void){
    moto_increaseLeftNormal();
    moto_increaseRightNormal();
    moto_increaseFrontNormal();
    moto_increaseRearNormal();
    PRINT_STRING("increases all motors");
    PRINT_NEW_LINE;
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson \n
           Magnus Bergqvist
 * @function moto_increaseAllPanic()
 * @param void
 * @return void
 * @brief Increases the pulse width of all the motors. Pulse width \n
          increases by a predefined so called "panic" step.
 */
void moto_increaseAllPanic(void){
    moto_increaseLeftPanic();
    moto_increaseRightPanic();
    moto_increaseFrontPanic();
    moto_increaseRearPanic();    
    PRINT_STRING("increases all motors");
    PRINT_NEW_LINE;
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson \n
           Magnus Bergqvist
 * @function moto_decreaseAllNormal()
 * @param void
 * @return void
 * @brief Decreases the pulse width of all the motors. Pulse width \n
          decreases by a predefined normal step.
 */
void moto_decreaseAllNormal(void){
    moto_decreaseLeftNormal();
    moto_decreaseRightNormal();
    moto_decreaseFrontNormal();
    moto_decreaseRearNormal();
    PRINT_STRING("decreases all motors\n");
    PRINT_NEW_LINE;
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson \n
           Magnus Bergqvist
 * @function moto_increaseAllPanic()
 * @param void
 * @return void
 * @brief Decreases the pulse width of all the motors. Pulse width \n
          decreases by a predefined so called "panic" step.
 */
void moto_decreaseAllPanic(void){
    moto_decreaseLeftPanic();
    moto_decreaseRightPanic();
    moto_decreaseFrontPanic();
    moto_decreaseRearPanic();
    PRINT_STRING("decreases all motors");
    PRINT_NEW_LINE;
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson \n
           Magnus Bergqvist
 * @function moto_increaseLeftNormal()
 * @function moto_increaseRightNormal()
 * @function moto_increaseFrontNormal()
 * @function moto_increaseRearNormal()
 * @function moto_increaseRightPanic()
 * @function moto_increaseLeftPanic()
 * @function moto_increaseFrontPanic()
 * @function moto_increaseRearPanic()
 * @param void
 * @return void
 * @brief Increases the pulse width of the corresponding motor.
 * @details Pulse width increases either by the predefined normal step or \n
            by the predefined "panic" step. Every value passed on to a \n
            motor will be mapped to individual max & min levels due to HW \n
            tolerances.
 */    
void moto_increaseLeftNormal(void){
    /* pulse is set to new value via a func. wich limits its maximum value */
    leftPulse = moto_LimitIncrease(leftPulse, NORMAL_STEP);
#ifdef ARDUINO
    /*
     * If runned on Arduino the value is mapped to the motors individual
     * min and max values and the pwm pin is set to this new value.
     */
    escLeft.writeMicroseconds(moto_map(
                            leftPulse, MIN_PULSE_LEFT, MAX_PULSE_LEFT));
#elif defined PC
    /* 
     * If runned on pc a stub function called analogWrite will receive the
     * mapped value and handle it according to which compilation flags that
     * are set.
     */
    analogWrite(LEFT_MOTOR, moto_map(
                            leftPulse, MIN_PULSE_LEFT, MAX_PULSE_LEFT));
#endif
    PRINT_STRING("Increasing left motor pulse");
    PRINT_NEW_LINE;
}

void moto_increaseRightNormal(void){
    /* See comments in moto_increaseLeftNormal */
    rightPulse = moto_LimitIncrease(rightPulse, NORMAL_STEP);
#ifdef ARDUINO
    escRight.writeMicroseconds(moto_map(
                            rightPulse, MIN_PULSE_RIGHT, MAX_PULSE_RIGHT));
#elif defined PC
    analogWrite(RIGHT_MOTOR, moto_map(
                            rightPulse, MIN_PULSE_RIGHT, MAX_PULSE_RIGHT));
#endif
    PRINT_STRING("Increasing right motor pulse");
    PRINT_NEW_LINE;
}

void moto_increaseFrontNormal(void){
    /* See comments in moto_increaseLeftNormal */
    frontPulse = moto_LimitIncrease(frontPulse, NORMAL_STEP);
#ifdef ARDUINO
    escFront.writeMicroseconds(moto_map(
                            frontPulse, MIN_PULSE_FRONT, MAX_PULSE_FRONT));
#elif defined PC
    analogWrite(FRONT_MOTOR, moto_map(
                            frontPulse, MIN_PULSE_FRONT, MAX_PULSE_FRONT));
#endif
    PRINT_STRING("Increasing Front motor pulse");
    PRINT_NEW_LINE;
}

void moto_increaseRearNormal(void){
    /* See comments in moto_increaseLeftNormal */
    rearPulse = moto_LimitIncrease(rearPulse, NORMAL_STEP);
#ifdef ARDUINO
    escRear.writeMicroseconds(moto_map(
                            rearPulse, MIN_PULSE_REAR, MAX_PULSE_REAR));
#elif defined PC
    analogWrite(REAR_MOTOR, moto_map(
                            rearPulse, MIN_PULSE_REAR, MAX_PULSE_REAR));
#endif
    PRINT_STRING("Increasing rear motor pulse");
    PRINT_NEW_LINE;
}

void moto_increaseLeftPanic(void){
    /* See comments in moto_increaseLeftNormal */
    leftPulse = moto_LimitIncrease(leftPulse, PANIC_STEP);
#ifdef ARDUINO
    escLeft.writeMicroseconds(moto_map(
                          leftPulse, MIN_PULSE_LEFT, MAX_PULSE_LEFT));
#elif defined PC
    analogWrite(LEFT_MOTOR, moto_map(
                          leftPulse, MIN_PULSE_LEFT, MAX_PULSE_LEFT));
#endif
    PRINT_STRING("Increasing left motor pulse in PANIC!");
    PRINT_NEW_LINE;
}

void moto_increaseRightPanic(void){
    /* See comments in moto_increaseLeftNormal */
    rightPulse = moto_LimitIncrease(rightPulse, PANIC_STEP);
#ifdef ARDUINO
    escRight.writeMicroseconds(moto_map(
                            rightPulse, MIN_PULSE_RIGHT, MAX_PULSE_RIGHT));
#elif defined PC
    analogWrite(RIGHT_MOTOR, moto_map(
                            rightPulse, MIN_PULSE_RIGHT, MAX_PULSE_RIGHT));
#endif
    PRINT_STRING("Increasing right motor pulse in PANIC!");
    PRINT_NEW_LINE;
}

void moto_increaseFrontPanic(void){
    /* See comments in moto_increaseLeftNormal */
    frontPulse = moto_LimitIncrease(frontPulse, PANIC_STEP);
#ifdef ARDUINO
    escFront.writeMicroseconds(moto_map(
                            frontPulse, MIN_PULSE_FRONT, MAX_PULSE_FRONT));
#elif defined PC
    analogWrite(FRONT_MOTOR, moto_map(
                            frontPulse, MIN_PULSE_FRONT, MAX_PULSE_FRONT));
#endif
    PRINT_STRING("Increasing Front motor pulse in PANIC!");
    PRINT_NEW_LINE;
}

void moto_increaseRearPanic(void){
    /* See comments in moto_increaseLeftNormal */
    rearPulse = moto_LimitIncrease(rearPulse, PANIC_STEP);
#ifdef ARDUINO
    escRear.writeMicroseconds(moto_map(
                            rearPulse, MIN_PULSE_REAR, MAX_PULSE_REAR));
#elif defined PC
    analogWrite(REAR_MOTOR, moto_map(
                            rearPulse, MIN_PULSE_REAR, MAX_PULSE_REAR));
#endif
    PRINT_STRING("Increasing rear motor pulse in PANIC!");
    PRINT_NEW_LINE;
}

/* !
 * @author Kristofer Hansson Aspman \n
           Björn Eriksson \n
           Magnus Bergqvist
 * @function moto_decreaseRightNormal()
 * @function moto_decreaseLeftNormal()
 * @function moto_decreaseFrontNormal()
 * @function moto_decreaseRearNormal()
 * @function moto_decreaseRightPanic()
 * @function moto_decreaseLeftPanic()
 * @function moto_decreaseFrontPanic()
 * @function moto_decreaseRearPanic()
 * @param void
 * @return void
 * @brief Decreases the pulse width of the corresponding motor.
 * @details Pulse width decreases either by the predefined normal step or \n
            by the predefined "panic" step. Every value passed on to a \n
            motor will be mapped to individual max & min levels due to HW \n
            tolerances.
 */
void moto_decreaseRightNormal(void){
    /* pulse is set to new value via a func. wich limits its maximum value */
    rightPulse = moto_LimitDecrease(rightPulse, NORMAL_STEP);
#ifdef ARDUINO
    /*
     * If runned on Arduino the value is mapped to the motors individual
     * min and max values and the pwm pin is set to this new value.
     */
    escRight.writeMicroseconds(moto_map(
                            rightPulse, MIN_PULSE_RIGHT, MAX_PULSE_RIGHT));
#elif defined PC
    /* 
     * If runned on pc a stub function called analogWrite will receive the
     * mapped value and handle it according to which compilation flags that
     * are set.
     */
    analogWrite(RIGHT_MOTOR, moto_map(
                            rightPulse, MIN_PULSE_RIGHT, MAX_PULSE_RIGHT));
#endif
    PRINT_STRING("Decreasing right motor pulse");
    PRINT_NEW_LINE;
}

void moto_decreaseLeftNormal(void){
    /* See comments in moto_decreaseRightNormal */
    leftPulse = moto_LimitDecrease(leftPulse, NORMAL_STEP);
#ifdef ARDUINO
    escLeft.writeMicroseconds(moto_map(
                            leftPulse, MIN_PULSE_LEFT, MAX_PULSE_LEFT));
#elif defined PC
    analogWrite(LEFT_MOTOR, moto_map(
                            leftPulse, MIN_PULSE_LEFT, MAX_PULSE_LEFT));
#endif
    PRINT_STRING("Decreasing left motor pulse");
    PRINT_NEW_LINE;
}

void moto_decreaseFrontNormal(void){
    /* See comments in moto_decreaseRightNormal */
    frontPulse = moto_LimitDecrease(frontPulse, NORMAL_STEP);
#ifdef ARDUINO
    escFront.writeMicroseconds(moto_map(
                            frontPulse, MIN_PULSE_FRONT, MAX_PULSE_FRONT));
#elif defined PC
    analogWrite(FRONT_MOTOR, moto_map(
                            frontPulse, MIN_PULSE_FRONT, MAX_PULSE_FRONT));
#endif
    PRINT_STRING("Decreasing Front motor pulse");
    PRINT_NEW_LINE;
}

void moto_decreaseRearNormal(void){
    /* See comments in moto_decreaseRightNormal */
    rearPulse = moto_LimitDecrease(rearPulse, NORMAL_STEP);
#ifdef ARDUINO
    escRear.writeMicroseconds(moto_map(
                            rearPulse, MIN_PULSE_REAR, MAX_PULSE_REAR));
#elif defined PC
    analogWrite(REAR_MOTOR, moto_map(
                            rearPulse, MIN_PULSE_REAR, MAX_PULSE_REAR));
#endif
    PRINT_STRING("Decreasing rear motor pulse");
    PRINT_NEW_LINE;
}

void moto_decreaseLeftPanic(void){
    /* See comments in moto_decreaseRightNormal */
    leftPulse = moto_LimitDecrease(leftPulse, PANIC_STEP);
#ifdef ARDUINO
    escLeft.writeMicroseconds(moto_map(
                            leftPulse, MIN_PULSE_LEFT, MAX_PULSE_LEFT));
#elif defined PC
    analogWrite(LEFT_MOTOR, moto_map(
                            leftPulse, MIN_PULSE_LEFT, MAX_PULSE_LEFT));
#endif
    PRINT_STRING("Decreasing left motor pulse in PANIC!");
    PRINT_NEW_LINE;
}

void moto_decreaseRightPanic(void){
    /* See comments in moto_decreaseRightNormal */
    rightPulse = moto_LimitDecrease(rightPulse, PANIC_STEP);
#ifdef ARDUINO
    escRight.writeMicroseconds(moto_map(
                            rightPulse, MIN_PULSE_RIGHT, MAX_PULSE_RIGHT));
#elif defined PC
    analogWrite(RIGHT_MOTOR, moto_map(
                            rightPulse, MIN_PULSE_RIGHT, MAX_PULSE_RIGHT));
#endif
    PRINT_STRING("Decreasing right motor pulse in PANIC!");
    PRINT_NEW_LINE;
}

void moto_decreaseFrontPanic(void){
    /* See comments in moto_decreaseRightNormal */
    frontPulse = moto_LimitDecrease(frontPulse, PANIC_STEP);
#ifdef ARDUINO
    escFront.writeMicroseconds(moto_map(
                            frontPulse, MIN_PULSE_FRONT, MAX_PULSE_FRONT));
#elif defined PC
    analogWrite(FRONT_MOTOR, moto_map(
                            frontPulse, MIN_PULSE_FRONT, MAX_PULSE_FRONT));
#endif
    PRINT_STRING("Decreasing Front motor pulse in PANIC!");
    PRINT_NEW_LINE;
}

void moto_decreaseRearPanic(void){
    /* See comments in moto_decreaseRightNormal */
    rearPulse = moto_LimitDecrease(rearPulse, PANIC_STEP);
#ifdef ARDUINO
    escRear.writeMicroseconds(moto_map(
                            rearPulse, MIN_PULSE_REAR, MAX_PULSE_REAR));
#elif defined PC
    analogWrite(REAR_MOTOR, moto_map(
                            rearPulse, MIN_PULSE_REAR, MAX_PULSE_REAR));
#endif
    PRINT_STRING("Decreasing rear motor pulse in PANIC!");
    PRINT_NEW_LINE;
}

/* !
 * @author Kristofer Hansson Aspman \n
           Magnus Bergqvist
 * @function printMotorStatus
 * @param void
 * @return void
 * @brief Prints out the status of the motors to either the \n
          terminal or the serial monitor depending on whether the ARDUINO \n
          or PC compilation flags are set together with the DEBUG flag.
 */
void printMotorStatus(void){
    PRINT_STRING("****************************");
    PRINT_NEW_LINE;
    PRINT_STRING("Current status of the motors");
    PRINT_NEW_LINE;
    PRINT_STRING("Right:  ");
    PRINT_DEC(rightPulse);
    PRINT_NEW_LINE;
    PRINT_STRING("Left:  ");
    PRINT_DEC(leftPulse);
    PRINT_NEW_LINE;
    PRINT_STRING("Front:  ");
    PRINT_DEC(frontPulse);
    PRINT_NEW_LINE;
    PRINT_STRING("Rear:  ");
    PRINT_DEC(rearPulse);
    PRINT_NEW_LINE;
    PRINT_STRING("****************************");
    PRINT_NEW_LINE;
}

/* !
 * @author Magnus Bergqvist
 * @function moto_LimitIncrease
 * @param uint16_t, uint16_t
 * @return uint16_t
 * @brief Returns a pulse width value witin the allowed spectrum.
 * @details moto_LimitIncrease takes the current pulse  width of a motor \n 
            and a increment step (normal or panic) as arguments and \n
            returns the new value after a check has been made if the new \n
            value is within the allowed pulse width spectrum. If the \n
            requested value is higher than the predefined MAX_ESC_PULSE, \n
            this very same variable is returned.
 */
uint16_t moto_LimitIncrease(uint16_t currentPulse,
                                        uint16_t increment){
    if((currentPulse + increment) < MAX_ESC_PULSE){
        return (currentPulse + increment);
    }
    else{
        return MAX_ESC_PULSE;
    }
}

/* !
 * @author Magnus Bergqvist
 * @function moto_LimitDecrease
 * @param uint16_t, uint16_t
 * @return uint16_t
 * @brief Returns a pulse width value witin the allowed spectrum.
 * @details moto_LimitDecrease takes the current pulse  width of a motor \n 
            and a decrement step (normal or panic) as arguments and \n
            returns the new value after a check has been made if the new \n
            value is within the allowed pulse width spectrum. If the \n
            requested value is lower than the predefined MIN_ESC_PULSE, \n
            this very same variable is returned.
 */
uint16_t moto_LimitDecrease(uint16_t currentPulse,
                                        uint16_t decrement){
    if((currentPulse - decrement) > MIN_ESC_PULSE){
        return (currentPulse - decrement);
    }
    else{
        return MIN_ESC_PULSE;
    }
}

/* !
 * @author Magnus Bergqvist
 * @function moto_map
 * @param uint16_t, uint16_t, uint16_t
 * @return uint16_t
 * @brief Returns a pulse width value adapted to a specific motor/ESC-pair.
 * @details The map function takes an input value (actual), and upper \n
            and lower boundary values for the wanted output as arguments. \n
            According to these values combined with boundaries for the \n
            systems actual output signals it returns a suitable \n
            value for the calling function to use.
 */
 
uint16_t moto_map(uint16_t actual, uint16_t lowerBoundary, 
                                    uint16_t upperBoundary){    
    /* 
     * step size depending on inner value spectrum 
     * compared to ESC output spectrum
     */
    double steps = (double)(upperBoundary - lowerBoundary) / 
                    (double)(MAX_ESC_PULSE - MIN_ESC_PULSE);
    
    /*
     * Calculating the result and make sure all values start from 
     * lowerBoundary
     */
    double result = lowerBoundary + ((actual-MIN_ESC_PULSE)*steps);
    
    /*
     * modfCrap is a variable to take care of int val. after a modf on result,
     * which we don't care about. We just want the decimal part to get
     * the rounding of the numbers more accurate
     */
    double modfCrap;
    
    /*
     * modfRest will store the decimals from var. result to be used below
     * to determine if the returned value should be rounded up or down
     */
    double modfRest = modf(result, &modfCrap);
    
    /* 
     * final created to get a return variable that conforms with the
     * coding standard and allows final adjustment to the result before
     * it's returned.
     */
    uint16_t final;
    
    /* If fractional part of result < 0.5 do nothing */
    if(modfRest < 0.5){
        final = (uint16_t)result;
    }
    /* Else add 1 to get a rounding upwards. */
    else{
        final = (uint16_t)result + 1;
    }
    
    /* 
     * A final check is performed to see that the result haven't been rounded
     * up or down so that it goes outside the boundaries.
     */   
    if (final >= lowerBoundary && final <= upperBoundary){
        return final;
    }
    else if(final < lowerBoundary){
        return lowerBoundary;
    }
    else{
        return upperBoundary;
    }
}
