                                                        
                                             
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
 * @file moto_recv.c
 * @version v0.02
 * @date 2011-05-18
 *
 * @brief Intended to pick up the message held by the protocol.\n
   Uses the types msg and msg_pointer defined in\n
   moto_msg_manipulation.h.
 *
 * @history 2011-05-18: Updated after code review. \n
                        Removed old moto_recvMsg() incl. variables \n
                        belonging to it. \n
                        (Magnus) \n
            2011-05-08: Now reads from the protocol. \n
                        (Kristofer) \n
            2011-04-14: Created the file. \n          
                        (Kristofer)
 */

#include "moto_recv.h"
#include "../../proto_mega/src/proto_lib.h"

msgStructPtr moto_recvMsg2(void){
    /* get message struct from protocol and return it */
    return (msgStructPtr)proto_read_motor2();
}

