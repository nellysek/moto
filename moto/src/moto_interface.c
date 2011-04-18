/*! @author Kristofer Hansson Aspman
 * @file moto_interface.c
 * @version v0.01
 * @date 2011-04-10
 * @brief Contains the implementations of moto_init and moto_run
 */

#ifdef ARDUINO
   #include "WProgram.h"
#elif defined PC
   #include <stdio.h>
#endif

#include "moto_interface.h"
#include "moto_msg_manipulation.h"
#include "moto_driver_functions.h"
#include "moto_msg_handler.h"

msg binary;
msg_pointer mp;

#ifdef ARDUINO
/* Pins for testing */
int ledPin = 13;
#endif

/*! @author Kristofer Hansson Aspman
 * @brief The init function requested by the CFG. It is
          called when the drone boots up.
 * @version v0.01
 * @date 2011-04-10
 * @param none
 * @return int (0 if correctly carried out)
 */
int moto_init(void){
  mp = &binary;
#ifdef ARDUINO
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
#elif defined PC
#endif
  return 0;
}

/*! @author Kristofer Hansson Aspman
 * @brief The run function requested by the CFG. It is run
          each scheduled cycle.
 * @version v0.01
 * @date 2011-04-10
 * @param none
 * @return int (0 if correctly carried out)
 */
int moto_run(void){
#ifdef ARDUINO
    binary = scanHexMsgSTDIN();
    examineID(mp);
  
/* This if statement is basically only for testing that leds light up */
    if(leftPulse > 0 && rightPulse > 0 && frontPulse > 0 && rearPulse > 0)
    {
        digitalWrite(13, HIGH);  
    }

    else
    {
        digitalWrite(13, LOW);
    }

    printMsg(mp);
    printMotorStatus();
#elif defined PC
    binary = scanHexMsgSTDIN();
    examineID(mp);
    printMsg(mp);
    printMotorStatus();
#endif
    return 0;
}
