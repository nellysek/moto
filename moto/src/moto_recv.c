/*!
 * @author Kristofer Hansson Aspman
 * @file moto_recv.c
 * @version v0.02
 * @date 2011-05-08
 *
 * @brief Intended to pick up the message held by the protocol.\n
 * Uses the types msg and msg_pointer defined in\n
 * moto_msg_manipulation.h.
 *
 * @history 2011-05-17: Updated after code review. \n
                        (Magnus) \n
            2011-05-08: Now reads from the protocol. \n
                        (Kristofer) \n
            2011-04-14: Created the file. \n          
                        (Kristofer)
 */

#include "moto_recv.h"
#include "../../proto_mega/src/proto_lib.h"

/* msg binary must be global so that a pointer to it can be returned */
msg binary;

msg_pointer moto_recvMsg(void){
    /* get message from protocol group and return it */
    uint8_t inputFromProto = proto_read_motor();
    binary = INT_TO_BITFIELD(&inputFromProto);
    return &binary;
}

msgStructPtr moto_recvMsg2(void){
    /* get message struct from protocol group and return it */
    return (msgStructPtr)proto_read_motor2();
}

