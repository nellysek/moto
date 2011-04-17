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
//Pins for testing
int ledPin = 13;
#endif

int moto_init(void){
  mp = &binary;
#ifdef ARDUINO
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
#elif defined PC
#endif
  return 0;
}

int moto_run(void){
#ifdef ARDUINO
  binary = scanHexMsgSTDIN();
  examineID(mp);
  
  if(leftMotor > 0 && rightMotor > 0 && frontMotor > 0 && rearMotor > 0){
    digitalWrite(13, HIGH);  
  }
  else
    digitalWrite(13, LOW);
  
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
