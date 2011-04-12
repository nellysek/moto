/**
 * Module:       parser.c
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

#include "moto_run.h"
#include "moto_msg_manipulation.h"
#include "moto_msg_handler.h"
#include "moto_driver_functions.h"
#include "moto_state_definitions.h"

//These definitions will go into a separate file later on.
#define STOP 0x00
#define STOP_ID 0x00
#define START 0x40
#define START_ID 0x01
#define CONTROL_ID 0x02
#define SPECIAL_COMMAND_ID 0x03
#define BAD_MESSAGE 0xf // when bits are not within the 0-255 range
#define GO_FORWARD 0xe3 // 1110 0011
#define GO_BACKWARD 0xc3 // 1100 0011

/* main(void){ */
/*   int x = 5; */
  
/*   while(x != 0){ */
/*     msg binary = scanHexMsgSTDIN(); */
/*     msg_pointer mp; */
/*     mp = &binary; */

/*     /\* mp->ID = CONTROL; *\/ */
/*     /\* binary.increase = 0; *\/ */
/*     /\* binary.front = 1; *\/ */
/*     /\* binary.rear = 1; *\/ */
  
/*     examineID(mp); */
/*     printMsg(mp); */
/*     printMotorStatus(); */
/*     x--; */
/*   } */
/*   return 0; */

/* } */

void examineID(msg_pointer mp){
#ifdef ARDUINO
  Serial.print("ID is ");
  Serial.println(mp->ID, DEC);
#elif defined PC
  printf("ID is %d\n", mp->ID);
#endif

  if (mp->ID == START_ID)
    {
      if (BITFIELD_TO_CHAR(mp) == BAD_MESSAGE){

#ifdef ARDUINO
	Serial.println("Bad message!");
#elif defined PC
	printf("Bad message!\n");
#endif
	return;
      }
      startMotors();
    }

  if (mp->ID == STOP_ID)
    {
      if (BITFIELD_TO_CHAR(mp) == BAD_MESSAGE){

#ifdef ARDUINO
	Serial.println("Bad message!");
#elif defined PC
	printf("Bad message!");
#endif
	return;
      }
      stopMotors();
    }

  if (mp-> ID == CONTROL_ID)
    controlMotors(mp);
  if (mp-> ID == SPECIAL_COMMAND_ID)
    specialMotorCommand(mp);

  return;

}

void controlMotors(msg_pointer mp){
#ifdef ARDUINO
  Serial.print("Standard Motor Control Message!\n");
#elif defined PC  
  printf("Standard Motor Control Message!\n");
#endif

  //Normal increase of the motors
  //i.e. panic mode not set.
  if (mp->increase == 1 && mp->panic == 0){
    if(mp->left == 1)
      increaseLeftNormal();
    if(mp->right == 1)
      increaseRightNormal();
    if(mp->front == 1)
      increaseFrontNormal();
    if(mp->rear == 1)
      increaseRearNormal();
  }

  //Panic increase of the motors
  //i.e. panic mode set.
  if (mp->increase == 1 && mp->panic == 1){
    if(mp->left == 1)
      increaseLeftPanic();
    if(mp->right == 1)
      increaseRightPanic();
    if(mp->front == 1)
      increaseFrontPanic();
    if(mp->rear == 1)
      increaseRearPanic();
  }
  
  //Normal decrease of the motors
  //i.e. panic mode not set.
  if (mp->increase == 0 && mp->panic == 0){
    if(mp->left == 1)
      decreaseLeftNormal();
    if(mp->right == 1)
      decreaseRightNormal();
    if(mp->front == 1)
      decreaseFrontNormal();
    if(mp->rear == 1)
      decreaseRearNormal();
  }
  
  //Panic decrease of the motors
  //i.e. panic mode set.
  if (mp->increase == 0 && mp->panic == 1){
    if(mp->left == 1)
      decreaseLeftPanic();
    if(mp->right == 1)
      decreaseRightPanic();
    if(mp->front == 1)
      decreaseFrontPanic();
    if(mp->rear == 1)
      decreaseRearPanic();
  }

  return;

}

void specialMotorCommand(msg_pointer mp){
#ifdef ARDUINO
  Serial.print("Special Motor Control Message!\n");
#elif defined PC
  printf("Special Motor Control Message!\n");
#endif

  if(BITFIELD_TO_CHAR(mp) == FORWARD)
    goForward();
  if(BITFIELD_TO_CHAR(mp) == BACKWARD)
    goBackward();
  
  return;

}


/**
 * Function:     msg scanHexMsgSTDIN()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description: When compiling for the ARDUINO this 
 *              converts the char given by serReadUnsignedChar()
 *              into a msg and returns it.
 *              When compiling for PC scanf() is used to read
 *              the variable.
 *              
 *
 */

msg scanHexMsgSTDIN(void){

#ifdef ARDUINO
    unsigned char input;
    Serial.println("Enter the message in hexadecimal!");
  
    input = serReadUnsignedChar();

    Serial.print("Number entered: ");
    Serial.println(input, HEX);
  
    if (input > -1 || input < 256)
        return INT_TO_BITFIELD(&input);
    else
        return INT_TO_BITFIELD(0xf);

#elif defined PC
    unsigned int input;
    printf("Enter the message in hexadecimal: ");
    scanf("%x", &input);
    return INT_TO_BITFIELD(&input);
#endif
}

/**
 * Function:     unsigned char serReadUnsignedChar()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description: Reads and stores what's currently in
 *              Serial.available() in an array.
 *              If there is something in the serial in
 *              then this is converted to an unsigned char
 *              with the help of sscanf() and returned.
 *              Otherwise 0xf is returned which is
 *              considered a bad message.
 *              Only used when compiled to ARDUINO.
 *              
 * Inspired by reply number 3 in this thread:
 * http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1191880368
 */

#ifdef ARDUINO
unsigned char serReadUnsignedChar(void)
{
  int i, serAva;          // i is a counter, serAva hold number of serial available
  unsigned char returnValue;               // the unsigned char to store the return value
  char inputBytes [7];                     // Array to hold input bytes
  char * inputBytesPtr = &inputBytes[0];   // Pointer to the first element of the array
  
  if (Serial.available()>0)                // Check to see if there are any serial input
    {
      delay(5);                              // Delay for terminal to finish transmitted
                                             // 5mS work great for 9600 baud (increase this number for slower baud)
      serAva = Serial.available();  // Read number of input bytes
      for (i=0; i<serAva; i++)       // Load input bytes into array
	inputBytes[i] = Serial.read();
      inputBytes[i] =  '\0';             // Adding a NULL character at the end
      
      sscanf(inputBytes, "%x", &returnValue); //Scans the character string and stores it as a hexadecimal
      return returnValue;
    }
    
  else
    return 0xf;                         // Return 0xf (0000 1111) if there is no input
}
#endif
