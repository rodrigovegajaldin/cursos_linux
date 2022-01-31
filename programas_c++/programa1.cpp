#include <iostream>

using namespace std;

class Caja{
	public:
		double largo;
		double ancho;
		double alto;
};

int main(){
	Caja caja1;
	Caja caja2;
	double volumen =0.0;

	//especificaciones de caja1
	caja1.alto = 5.0;
	caja1.largo = 6.0;
	caja1.ancho = 7.0;

	//espcificaciones de caja2
	caja2.alto = 10.0;
	caja2.largo = 12.0;
	caja2.ancho = 13.0;

	//volumen de caja1
	volumen = caja1.alto * caja1.largo * caja1.ancho;
	cout << "volumen de la caja 1 es: " << volumen << endl;

	//volumen de la caja2
	volumen = caja2.alto * caja2.largo * caja2.ancho;
	cout << "volumen de la caja 2 es: " << volumen << endl;

	return 0;
}
