/*!
 * @author Kristofer Hansson Aspman, Björn Eriksson, Magnus Bergqvist
 * @file moto_interface.c
 * @version v0.06
 * @date 2011-05-16
 * @history 2011-05-18 - Removed all traces of old code for parsing just \n
                         one 8 bit message. Now uses the 8x8 bit struct \n
                         as requested by the movement group. \n
                        (Kristofer)
            2011-05-17 - Updated after code review \n
                        (Magnus) \n
            2011-05-16 - Implemented no-op instructions \n
                        (Kristofer) \n
            2011-05-11 - Worked with ifdefs \n
                        (Magnus, Björn) \n
            2011-05-10 - Added support for struct containing 8 messages \n
                        (Magnus, Björn, Kristofer) \n
            2011-04-26 - Major cleanup and restructuring of the code\n
                        (Magnus, Björn, Kristofer) \n
            2011-04-10 - Created first version \n
                        (Magnus, Björn, Kristofer) \n

 * @brief Contains the implementations of moto_init and moto_run.\n
   Global variables set are: mp (a pointer to the hexadecimal \n
   message read from the protocol).
 */

#include <stdint.h>
#include "moto_recv.h"
#include "moto_interface.h"
#include "moto_driver_functions.h"
#include "moto_msg_handler.h"
#include "moto_printer_functions.h"
#include "moto_state_definitions.h"

#ifdef ARDUINO
    #include "../include/Servo.h"
    #include "WProgram.h"
#elif defined PC
    #include <stdio.h>
    #include "moto_stubs.h"
#endif

/* Stores the address to the actual bitfield containing the hex msg */
msg_pointer mp;

#ifdef ARDUINO
/* Servo "objects" definitions for the ESCs */
Servo escRight;
Servo escLeft;
Servo escFront;
Servo escRear;
#endif

/* !
 * @author Kristofer Hansson Aspman, Björn Eriksson, Magnus Bergqvist
 * @function moto_init
 * @param void
 * @return int16_t (0 if carried out correctly)
 * @brief The moto_init function requested by the CFG. It is called when \n
   the drone boots up.
 */
int16_t moto_init(void){
    PRINT_STRING("Inside moto_init");
    PRINT_NEW_LINE;
#ifdef ARDUINO
    escRight.attach(RIGHT_MOTOR);
    escLeft.attach(LEFT_MOTOR);
    escFront.attach(FRONT_MOTOR);
    escRear.attach(REAR_MOTOR);
    escRight.writeMicroseconds(STOP_PULSE);
    escLeft.writeMicroseconds(STOP_PULSE);
    escFront.writeMicroseconds(STOP_PULSE);
    escRear.writeMicroseconds(STOP_PULSE);
#endif
  moto_cyclesSinceLastMsg = 0;
  return 0;
}

/* !
 * @author Kristofer Hansson Aspman, Björn Eriksson, Magnus Bergqvist
 * @function moto_run
 * @param void
 * @return int16_t (0 if carried out correctly)
 * @brief The moto_run function requested by the CFG. It is run each \n
   scheduled cycle.
 * @details The binary message is read from the protocol and checked for \n
   both consistency and validity before it's sent to the parser. If no \n
   message has been written to the protocol by the movement component in \n
   more than 5000 cycles a no-op command is carried out (making the drone \n
   hover).\n
   Printouts will only be visible if the DEBUG flag is set.
 */
int16_t moto_run(void){
    moto_cyclesSinceLastMsg++;
    PRINT_STRING("Number of cycles without a message: ");
    PRINT_DEC(moto_cyclesSinceLastMsg);
    PRINT_NEW_LINE;

    /* 
     * Initiates no-op command if no message has been written to the protocol
     * in 5000 cycles. No-op command is currently set to HOVER but 
     * can be changed whatever command preferred.
     */
    if (moto_cyclesSinceLastMsg > 5000){
        PRINT_STRING("No new message in protocol for too long!");
        PRINT_NEW_LINE;
        PRINT_STRING("Initiating no-op command!");
        PRINT_NEW_LINE;

        /* Set the uint8_t to HOVER and then casting it to a msg 
         * before sending it to examineID() to be parsed.
         */
        uint8_t no_op_hex = HOVER;
        msg no_op_msg = INT_TO_BITFIELD(&no_op_hex);
        mp = &no_op_msg;
        examineID(mp);
        moto_cyclesSinceLastMsg = 0;
        return 0;
    }

    /* 
     * Creates a msgStructPtr and fetches data from mot_recvMsg2, it then
     * picks out the poiter to the first message in the struct. The rest
     * of the messages will be iterated over in the following for-loop
     */
    msgStructPtr mpStruct;
    mpStruct = moto_recvMsg2();
    mp = (msg_pointer)&(mpStruct->msg1);
    
    /* will always receive 8 messages in the loop from struct */
    uint8_t i;
    for(i = 0; i < 8; i++){
        PRINT_STRING("msg is: ");
        PRINT_HEX(BITFIELD_TO_CHAR(mp));
        PRINT_NEW_LINE;

        if(BITFIELD_TO_CHAR(mp) == 0xf1){
            PRINT_STRING("No new message in protocol");
            PRINT_NEW_LINE;
            return 0;
        }

        /*
         * Resets the counter that counts how many cycles has run since
         * last message was written to protocol.
         */
        moto_cyclesSinceLastMsg = 0;
        
        if(BITFIELD_TO_CHAR(mp) < 0x0 || BITFIELD_TO_CHAR(mp) > 0xff){
            PRINT_STRING("Message out of bounds");
            PRINT_NEW_LINE;
            return 0;
        }

        if(BITFIELD_TO_CHAR(mp) == 0xf){
            PRINT_STRING("No new message in scanhexmsg");
            PRINT_NEW_LINE;
            return 0;
        }

        if(BITFIELD_TO_CHAR(mp) == 0xB){
            PRINT_STRING("Struct does not contain more messages!");
            PRINT_NEW_LINE;
            return 0;
        }

        /* Message is well formed and is sent for further parsing */
        examineID(mp);

        printMsg(mp);
        printMotorStatus();
        
        /* pointer increment to get the next message in struct */
        mp++;
        }
    return 0;
}
