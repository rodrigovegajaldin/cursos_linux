//este programa vuelca un numero de 3 dijitos
#include <iostream>
#include <iomanip>//getline()
#include <string> //std::stoi()

using namespace std;
int main(){
    
    int numero,un,dec,cen;
    string texto;
    //cin>>var;
    cout<<"ingrese numero de 3 dijitos: ";
    cin>>numero;
    //numero = 123;
    //se aprvecha una propiedad del tipo de variable int solo toma la parte entera del numero
    un = (numero % 100) % 10;
    dec = (numero % 100) / 10;
    cen = numero / 100; 
    
    cout <<"\nel numero invertido es: "<<un<<dec<<cen<<endl;
    
    //esto es una prueba de como recivir texto con espacios desde el teclado
    cout<<"dame un texto:";
    getline(cin,texto);
    while (texto.length() == 0){//cuando se tiene una funcion de entrada de texto previa a getline() puede que el "enter" o "\n" de la entrada anterior la detecte como enter de esta funcion, entonces guarda vacio en la variable
    //por eso se debe de poner este while despues del getline, para corroborar que se reciva datos bien
        cout<<"se salto una vez"<<endl;
        getline(cin,texto);
    }
    //cin>>texto;
    cout<<"escribiste: "<<texto<<endl;

    string var = "n";
    int num;
    num = stoi(var);
    cout<<"la variable convertida es: "<<num<<endl;

    return 0;

}