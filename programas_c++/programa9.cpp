//este programa es una prueba de los tiempos de vida de las variables
//#include <iostream>
#include <cstdio>
//#include <thread>

struct Trazar {
    Trazar(const char* nombre): nombre{ nombre }{
        printf("%s contruida.\n",nombre);
    }
    ~Trazar(){
        printf("%s destruida.\n",nombre);
    }
    private:
        const char* const nombre;
};

static Trazar t1{"variable estatica"};
thread_local Trazar t2{"variable hilo local"};

int main(){
    printf("A\n");
    Trazar t3{"variable automatica"};
    printf("B\n");
    const auto* t4 = new Trazar{"variable dinamica"};
    printf("C\n");
    return 0;
}