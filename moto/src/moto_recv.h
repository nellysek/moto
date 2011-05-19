                                                        
                                             
/***************************************************************************
 * Copyright (C) 2011  Kristofer Hansson Aspman
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/*!
 * @author Kristofer Hansson Aspman
 * @file moto_recv.h
 * @version v0.02
 * @date 2011-05-18
 *
 * @brief Header file belonging to moto_recv.c.\n
   The functionality is described in the .c file.

 * @typedef msgStruct and msgStructPtr defined here and used for storing \n
   the binary message read from the protocol.
 *
 * @history 2011-05-18: Added som comments (Kristofer).
            2011-05-08: Now reads from the protocol.
 */

#ifndef MOTO_RECV_H
    #define MOTO_RECV_H
#include <stdint.h>
#include "moto_msg_manipulation.h"

/*!
 * @typedef msgStruct
 * @brief The type is used to store the binary message read from the \n 
   protocol. The uint8_t's are casted into the type "msg" in \n
   moto_interface.c. The type "msg" and its corresponding pointer type are \n
   defined in moto_msg_manipulation.h. \n
   This type was implemented due to a request from the movement group. They \n
   basically wanted to be able to send up to 8 binary messages instead of \n
   just one as was initially intended.
 */
typedef struct _msgStruct {
    uint8_t msg1;
    uint8_t msg2;
    uint8_t msg3;
    uint8_t msg4;
    uint8_t msg5;
    uint8_t msg6;
    uint8_t msg7;
    uint8_t msg8;
} msgStruct, *msgStructPtr;

/* Reads the message sent from the movement group to the protocol */
msgStructPtr moto_recvMsg2(void);

#endif
