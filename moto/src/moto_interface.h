/*!@author Kristofer Hansson Aspman, Björn Eriksson, Magnus Bergqvist
 * @file moto_interface.c
 * @version v0.05
 * @date 2011-05-11
 * @history 2011-05-11 - Worked with ifdefs
                        (Magnus, Björn)
            2011-04-26 - Major cleanup and restructuring of the code\n
                        (Magnus, Björn, Kristofer)
            2011-04-10 - Created first version
                        (Magnus, Björn, Kristofer)

 * @brief Contains the implementations of moto_init and moto_run.\n
          Global variables set are: mp (a pointer to the hexadecimal message
 *        read from the protocol).
 */

#ifndef MOTO_INTERFACE_H
    #define MOTO_INTERFACE_H
#ifdef ARDUINO_DBG
    #define ARDUINO
#endif

#ifdef ARDUINO
   #include "WProgram.h"
   #include "../include/Servo.h"
#elif defined PC
   #include <stdio.h>
#endif

#ifdef ARDUINO
extern Servo escRight;
extern Servo escLeft;
extern Servo escFront;
extern Servo escRear;
#endif

/* Stores the number of cycles since the last message was written to the
 * protocol by the movement group.
 */
static int moto_cyclesSinceLastMsg;

int moto_init(void);
int moto_run(void);
#endif
