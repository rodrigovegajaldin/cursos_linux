//uso de punteros
#include <cstdio>

int main(){
	int puntos{};//para asignar un puntero la variable asignada tiene que estar incializada
	int* puntos_direcc{&puntos};//asi se declara un putnero
	//entonces el en el puntero se guarda la direccion donde esta la variable puntos
	//int* puntos_direcc = &puntos //esta es otra forma de incializar el putnero
	printf("puntos: %d\n",puntos);
	printf("&puntos: %p\n", puntos_direcc);
	*puntos_direcc = 123;//con esta linea la variable puntos es la que tendra el valor 123
	printf("puntos2: %d\n",puntos);
	printf("&puntos2: %p\n", puntos_direcc);

}
