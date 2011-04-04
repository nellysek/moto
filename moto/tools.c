/**
 * Module:       tools.c
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description:  Contains the functions to make
 *               the life of a motor control
 *               programmer easier.
 *
 */


//TODO: Change the following two functions to macros instead.
unsigned char bitfieldToChar(msg_pointer mp){
  return *(unsigned char*)mp;
}

msg intToBitfield(unsigned int* ip){
  return *(msg_pointer)ip;
}

/**
 * Functions:    void scanDecMsgSTDIN()
 *               void scanHexMsgSTDIN()
 * Author(s):    Kristofer Hansson Aspman
 *
 * Description: Scans for a hex or decimal number 
 *              using scanf.
 *              
 *
 */
msg scanDecMsgSTDIN(){
  unsigned int input;
  printf("Enter the message in Decimal: ");
  scanf("%d", &input);
  return intToBitfield(&input);
}

msg scanHexMsgSTDIN(){
  unsigned int input;
  printf("Enter the message in hexadecimal: ");
  scanf("%x", &input);
  return intToBitfield(&input);
}

void printMsg(msg_pointer mp){

  printf("***********************************\n");
  printf("         Message Informatin\n");
  printf("\nBits are:\n-ID: %d\n-Incr: %d\n-Panic: %d\n",
	 mp->ID, mp->increase,
	 mp->panic);
  printf("-Left: %d\n-Right: %d\n-Front: %d\n-Rear: %d\n",
	 mp->left, mp->right, 
	 mp->front, mp->rear);

  printf("\nSize of bitfield: %ld\n", sizeof(*mp));
  printf("Hexadecimal representation: %x\n",
	 bitfieldToChar(mp));
  printf("Decimal representation: %d\n",
	 bitfieldToChar(mp));
  printf("***********************************\n");
}
