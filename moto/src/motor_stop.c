#include <stdio.h>
#include "motor_stop.h"
/* stop function 
 @uthor Bishare Sufi */

int stop() {
	unsigned char input = '0'; /* an example how to stop the motor*/

	printf("Stop => to '0'\n");

	while(input != '0'){
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
