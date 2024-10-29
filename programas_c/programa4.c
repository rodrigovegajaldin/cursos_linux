#include <string.h>
#include <stdio.h>

void main(){
	unsigned int counter =0;
	unsigned int counter2 =0;
	char msgaux2[13] = "";
	float var[2][2];
	printf("tamaño: %lu\n",sizeof(var[0][0]) );
	while (counter2 < 100){
		counter2 ++;
		if (counter < 72){
			counter ++;
			sprintf(msgaux2, "vuelta %d \r\n", counter);
			printf("%s",msgaux2);
		}else{
			printf("enviado\r\n");
			counter =0;
		}
	}
}
			
