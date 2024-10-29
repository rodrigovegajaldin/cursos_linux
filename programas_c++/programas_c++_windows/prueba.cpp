#include <iostream>
#include <fstream>
using namespace std;
//a)se escoge usar una estructura que contenga el nombre, CI y un array de servicios que los que el cliente pueda estar subscrito.
//b) basta con una estructura.

struct Cliente
{
    string nombre;
    int ci;
    string servicios [3]//se leera por codigo ejemplo si es servicio es telefonia fija se asigna 1001....;
    int deuda;
};
//c), d) y e)
void leer_datos_costo_servicioPopular(Cliente list[], int TAM, string nombreArchivo)
{	int costo = 0;
    int t1,t2,t3 = 0;
    fstream salida;
    salida.open(nombreArchivo, ios::in);

    if (salida.fail())
    {
        cout << "No se pudo abrir el archivo. Revisar permisos!" << endl;
    }
    else
    {
        
        for (int i = 0; i < TAM; i++)
        {	int count = 3;
            salida >> lista[i].nombre;
            salida >> lista[i].CI;
            for (int j = 0; j < count; ++j)
            {
            	salida >> lista[i].servicios;//Se leen los servicios por codigo y si no esta subscrito en ese servicio se supone que se puso algun otro parametro en vez del codigo del servicio
            	if(lis[i].servicios == "1001")
            	{
            		costo += 30;
            		t1++;
            	}
            		
            	else if (lis[i].servicios == "1002")
            	{
            		costo += 200;
            		t2++;
            	}
            	else if(lis[i].servicios == "1003")
            	{
            		costo += 150;
            		t3++;
            	}



				
            }
            
        }

        salida.close();
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

    cout << costo << endl;
}
int main()
{
	int TAM;
    cout<<"Ingresa el numero de Clientes a leer : ";
    cin>> TAM;
    Cliente listaclientes[TAM];
    leer_datos_costo_servicioPopular(listaclientes, TAM,"Clientes.txt");
	return 0;
}