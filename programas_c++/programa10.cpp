#include <cstdio>
#include <stdexcept>

struct RegistrarArchivo{
    void registrar_transfer(long de, long para, double cantidad){
        printf("[arch] %ld,%ld,%.2lf\n", de, para, cantidad);
        }
};
struct RegistrarConsola{
    void registrar_transfer(long de, long para, double cantidad){
        printf("[cons] %ld -> %ld: %.2lf\n",de, para, cantidad);
    }
};

enum class TipoRegistro{Consola, Archivo};

struct Enviar{
    Enviar() 
        : tipo{ TipoRegistro::Consola }{}
    void conf_registro(TipoRegistro nuevo_tipo){
        tipo = nuevo_tipo;
    };
    void hacer_transfer(long de, long para, double cantidad){
        switch (tipo){
            case TipoRegistro::Consola:{
                registrarConsola.registrar_transfer(de, para, cantidad);
                break;
            }
            case TipoRegistro::Archivo:{
                registrarArchivo.registrar_transfer(de, para, cantidad);
                break;
            }
            default:{
                throw std::logic_error("se encontro un tipo de registro desconocido");

            }
        }
    }
    private:
        TipoRegistro tipo;
        RegistrarConsola registrarConsola;
        RegistrarArchivo registrarArchivo;
};

int main(){
    Enviar enviar;
    enviar.hacer_transfer(1000, 2000, 49.95);
    enviar.hacer_transfer(2000, 4000, 20.00);
    enviar.conf_registro(TipoRegistro::Archivo);
    enviar.hacer_transfer(3000, 2000,75.56);
    return 0;
}