//este es un ejemplo de uso de clases abstractas
#include <cstdio>
#include <string>
class Poligono
{
    int num_lados;
    public:
    void setNumLados(int n){ num_lados = n; } /* Método concreto */
    virtual double calcularArea() = 0; /* Método virtual puro o abstracto */
    virtual double calcularPerimetro() = 0; /* Método virtual puro o abstracto */
};

class Triangulo: public Poligono
{
    public:
    double calcularArea()
    {
        /* Implementacion específica de la clase Triangulo */
    }
    
    double calcularPerimetro()
    {
        /* Implementacion específica de la clase Triangulo */
    }
};

class Hexagono: public Poligono
{
    public:
    double calcularArea()
    {
        /* Implementacion específica de la clase Hexagono */
    }
    
    double calcularPerimetro()
    {
        /* Implementacion específica de la clase Hexagono */
    }
};

//esta parte es practica de interfaces
class ElementoGraficoGenerico
{
    public:
    virtual void setColor(const double r, const double g, const double b) = 0;
    virtual void setPos(double xpos, double ypos) = 0;
    virtual void setLabel(const string lb) = 0;
    virtual void onClickPressed() = 0;
};

class LineaTexto: public ElementoGraficoGenerico
{
    /* Implementación específica de los métodos virtuales puros heredados */
};

class BotonOKCancel: public ElementoGraficoGenerico
{
    /* Implementación específica de los métodos virtuales puros heredados */
};

class CheckBox: public ElementoGraficoGenerico
{
    /* Implementación específica de los métodos virtuales puros heredados */
};

//este es prueba de override

class A{
    virtual void foo();
    void bar();
}
class B:A{
    void foo() const override; //esto dara error
    void foo() override;//OK foo si esta heredado en B
    void bar() override;//error A::bar no es virtual
}
int main(){

    return 0;
}