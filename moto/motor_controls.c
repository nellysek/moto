#include <stdio.h>
/**
 * Module:       motor_controls.c
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description:  Contains the functions that
 *               sets the pulse width of the
 *               different motors.
 *
 */

//TODO: Implement decrease functions and special
//      command functions.

#define NORMAL_INCREMENT 2
#define PANIC_INCREMENT 4
#define NORMAL_DECREMENT -2
#define PANIC_DECREMENT -4

//These are the variables keeping track of the 
//current state (pulse width) of each motor.
unsigned char leftMotor;
unsigned char rightMotor;
unsigned char frontMotor;
unsigned char rearMotor;

/**
 * Function:    void startMotors()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description: Sets the pulse width to a state where
 *              all motors starts spinning but the
 *              drone does not lift off.
 *
 */
void startMotors(){
  printf("Starting all motors\n");
}

/**
 * Function:    void stopMotors()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description: Stops all motors, i.e. sets the
 *              pulse width to zero.
 *
 */
void stopMotors(){
  printf("Stopping all motors\n");
}

/**
 * Function:    void goForward()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description: Increases the pulse width of
 *              of the rear motor and decreases
 *              the pulse width of the front
 *              motor. This makes the drone go
 *              forward.
 *
 */
void goForward(){
  printf("Increasing rear motor pulse\n");
  printf("Decreasing front motor pulse\n");
  increaseRearNormal();
  //decreaseFrontNormal();
  return;

}

/**
 * Function:    void goBackward()
 * Author(s):   Kristofer Hansson Aspman
 *
 * Description: Decreases the pulse width of
 *              of the rear motor and increases
 *              the pulse width of the front
 *              motor. This makes the drone go
 *              backward.
 *
 */
void goBackward(){
  printf("Increasing front motor pulse\n");
  printf("Decreasing rear motor pulse\n");
  return;

}


/**
 * Functions:   increaseLeftNormal()
 *              increaseRightNormal()
 *              increaseFrontNormal()
 *              increaseRearNormal()
 *              increaseLeftPanic()
 *              increaseRightPanic()
 *              increaseFrontPanic()
 *              increaseRearPanic()
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
void increaseLeftNormal(){
  printf("Increasing left motor pulse\n");
  leftMotor += NORMAL_INCREMENT;

}

void increaseRightNormal(){
  printf("Increasing right motor pulse\n");
  rightMotor += NORMAL_INCREMENT;
}

void increaseFrontNormal(){
  printf("Increasing Front motor pulse\n");
  frontMotor += NORMAL_INCREMENT;
}

void increaseRearNormal(){
  printf("Increasing rear motor pulse\n");
  rearMotor += NORMAL_INCREMENT;
}

void increaseLeftPanic(){
  printf("Increasing left motor pulse in PANIC!\n");
  leftMotor += PANIC_INCREMENT;

}

void increaseRightPanic(){
  printf("Increasing right motor pulse in PANIC!\n");
  rightMotor += PANIC_INCREMENT;
}

void increaseFrontPanic(){
  printf("Increasing Front motor pulse in PANIC!\n");
  frontMotor += PANIC_INCREMENT;
}

void increaseRearPanic(){
  printf("Increasing rear motor pulse in PANIC!\n");
  rearMotor += PANIC_INCREMENT;
}

void printMotorStatus(){
  printf("****************************\n");
  printf("Current status of the motors\n\n");
  printf("Left:  %d   Right: %d\n", leftMotor, rightMotor);
  printf("Front: %d   Rear:  %d\n", frontMotor, rearMotor);
  printf("****************************\n");
}
