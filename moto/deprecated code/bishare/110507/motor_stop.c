#include <stdio.h>
#include "motor_stop.h"
#define STOP_STATE '0'
/* stop function @uthor Bishare Sufi */
/* an idea created early in the project */

int stop() {
	unsigned char input = 0; 

	printf("Stop => to '0'\n");

	while(input != STOP_STATE){
		scanf("%c", &input);
		printf("Your input is: %c\n", input);
		printf("\n");
}

	printf("Motor stopped.\n");
        return 1;
}


int main(){
     stop();
return 0;
}
