#include <string.h>
#include <stdio.h>
void process(char* msg);

void process(char* msg){
	char *token;
	token=strtok(msg , "\n");
	if (token == NULL){
		printf("vacio\n");
		return;
	}
	while (token != NULL){
		//if (token != NULL){
			printf("mensaje: %s\n",token);
		//}
		token = strtok(NULL, "\n");
	}
}

void main(){
	char data[] = "perrito, cara de culo";
	char data2[] = "putito\nputito2\n";
	process(data);
	process(data2);
}
