#include <cstdio>

struct Hucha {
	int moneda;

	void add_moneda() {
		moneda ++;
	} 
};

int main(){
	Hucha miHucha;
	miHucha.moneda = 223;
	printf("Monedas: %d\n",miHucha.moneda);
	miHucha.add_moneda();
	printf("Monedas: %d\n",miHucha.moneda);

	
}
