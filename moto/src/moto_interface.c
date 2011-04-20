#ifdef ARDUINO_DBG
	#define ARDUINO
#endif

#ifdef ARDUINO
   #include "WProgram.h"
#elif defined PC_DBG
   #include <stdio.h>
#endif

#include "moto_interface.h"
#include "moto_msg_manipulation.h"
#include "moto_driver_functions.h"
#include "moto_msg_handler.h"

msg binary;
msg_pointer mp;

#ifdef ARDUINO
//Pins for testing
int ledPin = 13;
#endif

int moto_init(void){
  mp = &binary;
#ifdef ARDUINO
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
#elif defined PC_DBG
        //------------------------------------------------------missing
#endif
  return 0;
}

int moto_run(void){
#ifdef ARDUINO_DBG
  binary = scanHexMsgSTDIN();
  examineID(mp);

  if(leftPulse > 0 && rightPulse > 0 && frontPulse > 0 && rearPulse > 0){
    digitalWrite(13, HIGH);  
  }
  else
    digitalWrite(13, LOW);
  
  printMsg(mp);
  printMotorStatus();
#elif defined PC_DBG
    binary = scanHexMsgSTDIN();
    examineID(mp);
    printMsg(mp);
    printMotorStatus();
#endif
  return 0;
}
