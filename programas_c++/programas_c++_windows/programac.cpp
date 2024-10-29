#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void escribir();
void leer();
void costos();
void trend();
void pagoci();

struct cliente
{
    string nombre;
    string ci;
    string servicio1;//se leera por codigo ejemplo si es servicio es telefonia fija se asigna 1001....;
    string servicio2;
    string servicio3;
};

int main(){
	//escribir();
	leer();
	return 0;
}

void escribir(){
	ofstream archivo;
	archivo.open("archivo.txt",ios::out); //asi se crea archivos 
	if(archivo.fail()){
		cout << "no se pudo crear el archivo";
		exit(1);
	}

	archivo << "Hola que tal diaz\nlinea 2";
	archivo.close();
}

void costos(cliente lista[]){
	//cout << "------------------";
	int costo =0;
	for(int i=0;i<6;i++){
		//cout << "nombre es " << lista[i].nombre <<endl;
		//cout << "ci es " << lista[i].ci <<endl;
		//cout << "servicio1 es " << lista[i].servicio1 <<endl;
		//cout << "servicio2 es " << lista[i].servicio2 <<endl;
		//cout << "servicio3 es " << lista[i].servicio3 <<endl;
		if(lista[i].servicio1 == "1001" || lista[i].servicio2 == "1001" || lista[i].servicio3 == "1001"){
            		costo += 30;
            		//t1++;
        }		
        if (lista[i].servicio1 == "1002" || lista[i].servicio2 == "1002" || lista[i].servicio3 == "1002"){
            costo += 200;
            //t2++;
        }
    	if(lista[i].servicio1 == "1003" || lista[i].servicio2 == "1003" || lista[i].servicio3 == "1003"){
            costo += 150;
            //t3++;
        }
	}
	cout << "El total de ventas del servicio de la empresa es: "<< costo<< endl;
}

void trend(cliente lista[]){
	//cout << "------------------";
	int t1,t2,t3 =0;
	for(int i=0;i<6;i++){
		//cout << "nombre es " << lista[i].nombre <<endl;
		//cout << "ci es " << lista[i].ci <<endl;
		//cout << "servicio1 es " << lista[i].servicio1 <<endl;
		//cout << "servicio2 es " << lista[i].servicio2 <<endl;
		//cout << "servicio3 es " << lista[i].servicio3 <<endl;
		if(lista[i].servicio1 == "1001" || lista[i].servicio2 == "1001" || lista[i].servicio3 == "1001"){
            		 
            		t1++;
        }		
        if (lista[i].servicio1 == "1002" || lista[i].servicio2 == "1002" || lista[i].servicio3 == "1002"){
           t2++;
        }
    	if(lista[i].servicio1 == "1003" || lista[i].servicio2 == "1003" || lista[i].servicio3 == "1003"){
            t3++;
        }
	}
	if(t1 > t2 && t1 >t3)
    {
    	cout << "el servicio mas utilizdo es telefonia fija" << endl;
    }
    else if(t2 > t1 && t2 >t3)
    {
    	cout << "el servicio mas utilizado internet" << endl;
    }
    else if(t3 > t1 && t3 >t2)
    {
    	cout << "el servicio mas utilizado es televisión por cable " << endl;
    }
    else 
    	cout << "no existe un servicio mas utilizado" <<endl;
}

void pagoci(cliente lista[],string CI){
		int costo = 0;
		for(int i=0;i<6;i++){
		//cout << "nombre es " << lista[i].nombre <<endl;
		//cout << "ci es " << lista[i].ci <<endl;
		//cout << "servicio1 es " << lista[i].servicio1 <<endl;
		//cout << "servicio2 es " << lista[i].servicio2 <<endl;
		//cout << "servicio3 es " << lista[i].servicio3 <<endl;
		if (lista[i].ci==CI){
			if(lista[i].servicio1 == "1001" || lista[i].servicio2 == "1001" || lista[i].servicio3 == "1001"){
	            		costo += 30;
	            		//t1++;
	        }		
	        if (lista[i].servicio1 == "1002" || lista[i].servicio2 == "1002" || lista[i].servicio3 == "1002"){
	            costo += 200;
	            //t2++;
	        }
	    	if(lista[i].servicio1 == "1003" || lista[i].servicio2 == "1003" || lista[i].servicio3 == "1003"){
	            costo += 150;
	            //t3++;
	        }
	        cout<<"el cliente "<<lista[i].nombre<<" debe " << costo<<endl;
    	}
	}
}

void leer(){
	ifstream archivo;
	archivo.open("servicios.txt",ios::in);//asi se lee un archivo
	string texto;
	string delimiter =",";
	int contar = 0;
		if(archivo.fail()){
		cout << "no se pudo leer el archivo";
		exit(1);
	}
	struct cliente lista[100];
	while(!archivo.eof()){
		getline(archivo,texto);
		cout << texto << endl;
		string token="";
		size_t pos = 0;

		int lugar = 0;
		while ((pos=texto.find(delimiter)) != std::string::npos) {
    		token = texto.substr(0, pos);
    		//cout << token << endl;
    		texto.erase(0,  pos+ delimiter.length());
    		if (lugar == 0){
    			lista[contar].nombre = token;
    			cout << "nombre es " << lista[contar].nombre <<endl;
    		}
    		else if(lugar == 1){
    			lista[contar].ci = token;
    			cout << "ci es " << lista[contar].ci <<endl;
    		}
    		else if(lugar == 2){
    			lista[contar].servicio1 = token;
    			cout << "servicio1 es " << lista[contar].servicio1 <<endl;
    		}
    		else if(lugar == 3){
    			lista[contar].servicio2 = token;
    			cout << "servicio2 es " << lista[contar].servicio2 <<endl;
    		}
    		else if(lugar == 4){
    			lista[contar].servicio3 = token;
    			cout << "servicio3 es " << lista[contar].servicio3 <<endl;
    		}
    		lugar ++;
		}
		//cout << texto << endl;
		contar ++;
	}
	archivo.close();
	//costos(lista[100]);

	costos(lista);
	trend(lista);
	pagoci(lista,"20");
}



