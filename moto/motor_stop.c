#include <stdio.h>
/* stop function 
 @uthor Bishare Sufi */

int stop(void);

int stop() {
	char stop = 0;

	printf("Stop => to '0'\n");

	while(stop != '0'){
		scanf("%c", &stop);
		printf("You type: %c\n", stop);
		printf("\n");

	}

	printf("Motor stopped.\n");
}

int main(){
     stop();
return 0;
}
