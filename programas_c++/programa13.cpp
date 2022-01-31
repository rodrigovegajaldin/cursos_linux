//este programa esa la prueba del uso de ++variable y variable++
#include <iostream>
#include <math.h> //pow() esto es para elevar al cuadrado
using namespace std;

int main(){
    int variable=0;
    int variable2 = 0;
    cout << "con el operador despues" <<variable++<<endl;//cuando el operador esta despues DEVUELVE EL ORIGINAL Y DESPUES INCREMENTA
    cout << "con el operador despues" <<pow(++variable,2)<<endl;//recie se ve el cambio
    cout << "con operador antes"<<++variable2<<endl;//cuando el operador esta antes PRIMERO INCREMENTA Y MUESTRA EL CAMBIADO
    int v = true;
    int f = false;
    cout<< "verdadero es : "<<v<<endl;
    cout<< "falso es : "<<f<<endl;
    cout <<"bytes: "<<hex<<10<<endl;
    cout << "decimal: "<<dec<<0x10<<endl;
    float variable3 = static_cast<float>(variable);
    cout << "nueva variable: "<< variable3 <<endl;
    
    //printf("la variable es: %d - %d\n",++variable,variable++);
    return 0;
}
