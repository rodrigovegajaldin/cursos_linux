//esto prueba como setear la presicion de decimales
#include <string.h>
#include <stdio.h>

void main(){
	float a = 5.123456;
	printf("hola%5.2fchau\n",a);
	float numero = 3.123456789;
	unsigned int bytes[4];
	*((float*)bytes) = numero;
	printf("numero: %ls\n",bytes);
	unsigned int numero_byte[sizeof(float)];
	memcpy(numero_byte, &numero, sizeof(float));
	printf("tamano de float: %ld\n",sizeof(bytes));
	int var1;
	float var2[5];
	int var3;
	printf("inicio var 1: %p tamaño: %ld\n",&var1, sizeof(var1) );
	printf("inicio var 2: %p tamaño: %ld\n",&var2, sizeof(var2) );
	printf("inicio var 2b: %p tamaño: %ld\n",&var2[1], sizeof(var2[1]) );
	printf("inicio var 3: %p tamaño: %ld\n",&var3, sizeof(var3) );
	int var4=0;
	(11<2) ? (var4 = 1) : (var4=2);
	printf("condicion es: %d\n",var4);
	int b;
	b = a;
	printf("valor original: %f\n",a);
	printf("nuevo valor: %d\n",b);
	float matriz [3][3]={1,1,1,1,1,1};
	printf("tamaño de matriz (36): %ld",sizeof(matriz));
	for (int pq=0; pq<3;pq++){
		for (int qp=0;qp<3;qp++){
			printf("ubicacion [%d][%d], ubicacion: %p\n",pq,qp,&matriz[pq][qp]);
			}
	}
	float var5 = 0;
	printf("comparacion 5 :%d\n",var5==0);
}
