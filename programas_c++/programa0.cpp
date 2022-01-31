//esto es para testear los tipos de variable
//#include <cstdio>
#include <tuple>//std::tuple, std::make_tuple, std::tie
#include <iostream>//std::cout, std::cin

using namespace std;

struct calculadora{
    int mensaje(){
        int opcion=0;    
        cout<<"MENU DE OPCIONES"<<endl;
        cout<<"1. Sumar"<<endl;
        cout<<"2. Restar"<<endl;
        cout<<"3. Multiplicar"<<endl;
        cout<<"4, Dividir"<<endl;
        cout<<"escribe opcion: ";
        cin>>opcion;
        //cout<<"variable dentro de la funcion: "<<opcion+1<<endl;
        return opcion;
    }
    tuple<int, int> pedir(){//si no se usa el "using namespace std" tendira que ser std::tuple
        int n1, n2;
        cout<<"ingrese primer numero: ";
        cin>>n1;
        cout<<"ingrese segundo numero: ";
        cin>>n2;
        return make_tuple(n1,n2);
    }
    float operacion(int opcion){
        int n1, n2;
        float resultado;
        tie(n1,n2) = calculadora::pedir();//de esta manera utilizo una funcion dentro de la misma clase
        switch (opcion){
            case 1:
                cout<<"\nSELECCIONO SUMA"<<endl;
                resultado = n1+n2;
                break;
            case 2:
                cout<<"\nSELECCIONO RESTA"<<endl;
                resultado = n1-n2;
                break;
            case 3:
                cout<<"\nSELECCIONO MULTIPLICACION"<<endl;
                resultado = n1*n2;
                break; 
            case 4:
                cout<<"\nSELECCIONO DIVICION"<<endl;
                resultado = n1/n2;
                break;        
            default:
                cout<<"\nLA OPCION ESTA MAL: "<<opcion<<endl;                   
        }
        return resultado;
    }
};

//char* var = "rodrigo vega";//este formato de usar string sirve tanto para <iostream> o para <cstdio>
string var = "rodrigo vega"; //esto solo funciona con <iostream>
int main(){
    printf("la variable dice %s\n",var.c_str());//esta es la forma correcta de imprimir string con printf
    //yo recomiendo usar <iostream> y el tipo de variable string 
    //cout<<var<<endl;

    //aqui es como usar tuplas
    int myint;
    char mychar;

    tuple<int,float,char> mytuple;//asi se DECLARA UNA TUPLA

    mytuple = make_tuple (10, 2.6, 'a');//asi se DEFINE UNA TUPLA          
    tie (myint, ignore, mychar) = mytuple; //asi de SEPARA UNA TUPLA 
    printf("esta es la prueba de las tupla: %d , %c\n",myint,mychar);

    if (10<5){
         printf("este es el if");
    }else if(10>5){
        printf("este es el else");
    }
    //desde aqui es la calculadora
    int opcion;
    float resultado;
    calculadora calc;
    opcion = calc.mensaje();
    resultado = calc.operacion(opcion);
    printf("\nRESULTADO DE LA OPERACION: %f\n",resultado);
    
    return 0;
}