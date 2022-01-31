#include <cstdio>

class Completa{
	public:
		Completa(){
			printf("sin argumentos\n");
		}
		Completa(char x){
			printf("char: %c\n",x);
		}
		Completa(int x){
			printf("int: %d\n",x);
		}
		Completa(float x){
			printf("float: %f\n",x);
		}
};

int main(){
	Completa c1;//esto llama al constructo sin argumentos
	Completa c2{ 'd' };//poniendo las llaves invocan al constructo esperado
	Completa c3{ 54321 };
	Completa c4{ 2.01e5f };
	Completa c5( 'h' );
	Completa c6 = { '3' };
	Completa c7{};
	Completa c8();//este no tendra salida poq es la declaracion de una funcion entonces es necesario crear una funcion 
}
