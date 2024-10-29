#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
#include <fstream>
using namespace std;

void jugardos();
void juegacompu();
struct tablero2{
	char datos[3][3] = { {'1','2','3'},
					   {'4','5','6'},
					   {'7','8','9'}
						};
};
bool turnoDeX = false;


char hayGanador(tablero2 tabla){
	//Posicion horizontal
	for(int i = 0 ; i < 3 ; i++){
		if(tabla.datos[i][0] == tabla.datos[i][1] && tabla.datos[i][1] == tabla.datos[i][2] ){
			return tabla.datos[i][0];

		}
	}
	//Posicion vertical
	for(int i = 0 ; i < 3 ; i++){
		if(tabla.datos[0][i] == tabla.datos[1][i] && tabla.datos[1][i] == tabla.datos[2][i] ){
			return tabla.datos[0][i];

		}
	}

	//Posicion Diagonal de izquierda a derecha
	if(tabla.datos[0][0] == tabla.datos[1][1] && tabla.datos[1][1] == tabla.datos[2][2] ){
		return tabla.datos[0][0];

	}

	//Posicion Diagonal de Derecha a Izquierda
	if(tabla.datos[0][2] == tabla.datos[1][1] && tabla.datos[1][1] == tabla.datos[2][0] ){
		return tabla.datos[0][2];
	}
	return '_';
}

bool hayEmpate(tablero2 tabla){
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			if((int)tabla.datos[i][j] < 58){
				return false;
			}
		}
	}
	return true;
}

void display(tablero2 tabla){
	printf("\t\t\t\tT i c	t a c	t o e");
	printf("\nPlayers 1 Symbol: X");
	printf("\nPlayers 2 Symbol: O");
	printf("\n\t\t\t       |       |       ");
	printf("\n\t\t\t   %c   |   %c   |   %c   ",tabla.datos[0][0],tabla.datos[0][1],tabla.datos[0][2]);
	printf("\n\t\t\t-------|-------|-------");
	printf("\n\t\t\t   %c   |   %c   |   %c   ",tabla.datos[1][0],tabla.datos[1][1],tabla.datos[1][2]);
	printf("\n\t\t\t-------|-------|-------");
	printf("\n\t\t\t   %c   |   %c   |   %c   ",tabla.datos[2][0],tabla.datos[2][1],tabla.datos[2][2]);
	printf("\n\t\t\t       |       |       \n");
}

void jugardos(tablero2 tabla){
	bool termina = false;
	ofstream archivo;
	archivo.open("archivo.txt",ios::out); //asi se crea archivos 
	if(archivo.fail()){
		cout << "no se pudo crear el archivo";
		exit(1);
	}
	while(!termina){
		bool repetido = false;
		system("cls");
		char jugador = turnoDeX ? 'X' : 'O';
		int lugar = 0;
		display(tabla);
		cout << "Es el turno de " << jugador << endl;
		cout << "En que posicion quieres marcar?"<<endl;
		cin >> lugar;
		for (int i = 0 ; i < 3 ; i++){
			for (int j = 0 ; j < 3 ; j++){
				if ((int)tabla.datos[i][j] == 48 + lugar){
					tabla.datos[i][j] = jugador;
					turnoDeX = !turnoDeX;
				}
				archivo << tabla.datos[i][j];
			}
			archivo << "\n";
		}
		display(tabla);
		char ganador  = hayGanador(tabla);
		if( ganador != '_'){
			cout << " Ha ganado " << ganador << endl;
			termina = true;
			archivo.close();
		}
		else if(hayEmpate(tabla)){
			cout << " Hay un empate" << endl;
			termina = true;
			archivo.close();
		}
	}
}


void juegacompu(tablero2 tabla){
	bool termina = false;
	ofstream archivo;
	archivo.open("archivo.txt",ios::out); //asi se crea archivos 
	if(archivo.fail()){
		cout << "no se pudo crear el archivo";
		exit(1);
	}
	while(!termina){
		int nuevo;
		bool repetido = false;
		system("cls");
		char jugador = turnoDeX ? 'X' : 'O';
		int lugar = 0;
		display(tabla);
		cout << "Es el turno de " << jugador << endl;
		if (jugador == 'O'){
			cout << "En que posicion quieres marcar?"<<endl;
			cin >> lugar;
		}else if (jugador == 'X'){
			srand(time(NULL));
			lugar = 1+rand()%(10-1);
		}
		for (int i = 0 ; i < 3 ; i++){
			for (int j = 0 ; j < 3 ; j++){
				if ((int)tabla.datos[i][j] == 48 + lugar){
					tabla.datos[i][j] = jugador;
					turnoDeX = !turnoDeX;
				}		

				archivo << tabla.datos[i][j];
			}
			archivo << "\n";
		}
		display(tabla);
		char ganador  = hayGanador(tabla);
		if( ganador != '_'){
			cout << " Ha ganado " << ganador << endl;
			termina = true;
			archivo.close();
		}
		else if(hayEmpate(tabla)){
			cout << " Hay un empate" << endl;
			termina = true;
			archivo.close();
		}
	}
}


int main(int argc, char **argv) {

	while(true){
		string respuesta;
		string respuesta2;
		bool solo = false;
		struct tablero2 tabla;
		cout << "QUIERES JUGAR SOLO?(s , n)" << endl;
		cin >> respuesta;
		if (respuesta == "s"){
			//solo = true;
			//display(tabla);
			juegacompu(tabla);
		}else if(respuesta == "n"){
			jugardos(tabla);
			//mostrarTablero(tabla);
		}
		cout << "QUIERES VOLVER A JUGAR?(s , n)" << endl;
		cin >> respuesta2;
		if (respuesta2 == "n"){
			//archivo.close();
			exit(1);
		}
	}
}
