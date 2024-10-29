#include <string.h>
#include <stdio.h>
static char commands[][25] = {"AT\r\n",
		"AT+DISC?\r\n",
		"AT+START\r\n",
		"AT+FINDALLCHARS?\r\n",
		"AT+SET_WAYWN----\r\n",
		"AT+NOTIFY_ON----\r\n"};
void main(){
	char var[5] = "";
	char var2[5] = "at+p";
	char aux[6];
	if (var[0] == '\0')
		printf("el vacio");
	memcpy(aux,&var,3);
	//aux[2] = '\0';
       if (strcmp(aux , "at+")==0){
	       printf("variabel 1\n");
       }
	memcpy(aux,&var2,3);
	//aux[2] = '\0';
       if (strcmp(aux , "at+")==0){
	       printf("variable 2\n");
       }
       printf("termino\n");
       

       //desde aqui pruebo a sustituir valores de la variable commands
       sprintf(commands[4],"AT+SET_WAYWN%s\r\n" , "1234");
       printf("la sustituida: %s\r\n",commands[3]); 
       printf("comparacion %d\r\n", 1==2);
       for (int i=0; i<6; i++){
	       printf("comando: %d\n",i);
	       printf("comando: %s\n",commands[i]) ;
	       printf("tamaÑo: %zu\n", strlen(commands[i]) );
	}
}
