#include <stdint.h>

#ifdef ARDUINO_DBG
    #define ARDUINO
#endif
#ifdef ARDUINO
   #include "WProgram.h"
#elif defined PC
   #include <stdio.h>
#endif

#define INT_TO_BITFIELD(a) *(msg_pointer)a
#define BITFIELD_TO_CHAR(a) *(uint8_t*)a

/*Big endian control message*/
typedef struct control_message{
  uint8_t rear :1;
  uint8_t front :1;
  uint8_t left :1;
  uint8_t right :1;
  uint8_t panic :1;
  uint8_t increase :1;
  uint8_t ID :2;
} msg, *msg_pointer;

/*Little endian control message*/
/* struct control_message{ */
/*   uint8_t ID :2; */
/*   uint8_t increase :1; */
/*   uint8_t panic :1; */
/*   uint8_t right :1; */
/*   uint8_t left :1; */
/*   uint8_t front :1; */
/*   uint8_t rear :1; */

/* } msg; */

void printMsg(msg_pointer mp);
