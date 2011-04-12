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
unsigned char rightMotor;
unsigned char leftMotor;
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
void startMotors(void){
#ifdef ARDUINO
  Serial.print("Starting all motors\n");
#elif defined PC
  printf("Starting all motors\n");
#endif
  rightMotor += NORMAL_INCREMENT;
  leftMotor += NORMAL_INCREMENT;
  frontMotor += NORMAL_INCREMENT;
  rearMotor += NORMAL_INCREMENT;    
}

/**
 * Function:    void stopMotors()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description: Stops all motors, i.e. sets the
 *              pulse width to zero.
 *
 */
void stopMotors(void){
#ifdef ARDUINO
  Serial.print("Stopping all motors\n");
#elif defined PC
  printf("Stopping all motors\n");
#endif
  rightMotor = 0;
  leftMotor = 0;
  frontMotor = 0;
  rearMotor = 0;
    
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
void goForward(void){
#ifdef ARDUINO
  Serial.print("Increasing rear motor pulse\n");
  Serial.print("Decreasing front motor pulse\n");
#elif defined PC
  printf("Increasing rear motor pulse\n");
  printf("Decreasing front motor pulse\n");
#endif
  increaseRearNormal();
  decreaseFrontNormal();
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
void goBackward(void){
#ifdef ARDUINO
  Serial.print("Increasing front motor pulse\n");
  Serial.print("Decreasing rear motor pulse\n");
#elif defined PC
  printf("Increasing front motor pulse\n");
  printf("Decreasing rear motor pulse\n");
#endif
  decreaseRearNormal();
  increaseFrontNormal();

  return;

}

/**
 * Functions:   increaseRightNormal()
 *              increaseLeftNormal()
 *              increaseFrontNormal()
 *              increaseRearNormal()
 *              increaseRightPanic()
 *              increaseLeftPanic()
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
void increaseLeftNormal(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Increasing left motor pulse\n");
  leftMotor += NORMAL_INCREMENT;
#endif

}

void increaseRightNormal(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Increasing right motor pulse\n");
  rightMotor += NORMAL_INCREMENT;
#endif
}

void increaseFrontNormal(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Increasing Front motor pulse\n");
  frontMotor += NORMAL_INCREMENT;
#endif
}

void increaseRearNormal(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Increasing rear motor pulse\n");
  rearMotor += NORMAL_INCREMENT;
#endif
}

void increaseLeftPanic(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Increasing left motor pulse in PANIC!\n");
  leftMotor += PANIC_INCREMENT;
#endif

}

void increaseRightPanic(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Increasing right motor pulse in PANIC!\n");
  rightMotor += PANIC_INCREMENT;
#endif
}

void increaseFrontPanic(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Increasing Front motor pulse in PANIC!\n");
  frontMotor += PANIC_INCREMENT;
#endif
}

void increaseRearPanic(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Increasing rear motor pulse in PANIC!\n");
  rearMotor += PANIC_INCREMENT;
#endif
}

/**
 * Functions:   decreaseRightNormal()
 *              decreaseLeftNormal()
 *              decreaseFrontNormal()
 *              decreaseRearNormal()
 *              decreaseRightPanic()
 *              decreaseLeftPanic()
 *              decreaseFrontPanic()
 *              decreaseRearPanic()
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

void decreaseRightNormal(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Decreasing right motor pulse\n");
  rightMotor += NORMAL_DECREMENT;
#endif
}

void decreaseLeftNormal(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Decreasing left motor pulse\n");
  leftMotor += NORMAL_DECREMENT;
#endif
}

void decreaseFrontNormal(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Decreasing Front motor pulse\n");
  frontMotor += NORMAL_DECREMENT;
#endif
}

void decreaseRearNormal(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Decreasing rear motor pulse\n");
  rearMotor += NORMAL_DECREMENT;
#endif
}

void decreaseLeftPanic(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Decreasing left motor pulse in PANIC!\n");
  leftMotor += PANIC_DECREMENT;
#endif
}

void decreaseRightPanic(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Decreasing right motor pulse in PANIC!\n");
  rightMotor += PANIC_DECREMENT;
#endif
}

void decreaseFrontPanic(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Decreasing Front motor pulse in PANIC!\n");
  frontMotor += PANIC_DECREMENT;
#endif
}

void decreaseRearPanic(void){
#ifdef ARDUINO 
#elif defined PC
  printf("Decreasing rear motor pulse in PANIC!\n");
  rearMotor += PANIC_DECREMENT;
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
  Serial.println(rightMotor, DEC);
  Serial.print("Left:  ");
  Serial.println(leftMotor, DEC);
  Serial.print("Front:  ");
  Serial.println(frontMotor, DEC);
  Serial.print("Rear:  ");
  Serial.println(rearMotor, DEC);
  Serial.println("****************************");
  //Arduino code end
#elif defined PC
  //PC code begin
  printf("****************************\n");
  printf("Current status of the motors\n\n");
  printf("Left:  %d   Right: %d\n", leftMotor, rightMotor);
  printf("Front: %d   Rear:  %d\n", frontMotor, rearMotor);
  printf("****************************\n");
  //PC code end
#endif
}