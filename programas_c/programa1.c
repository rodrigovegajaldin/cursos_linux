#include <stdint.h>
#include <string.h>

int main() {
    // Declarar e inicializar un arreglo de caracteres
    unsigned int var[] = "Hola, Mundo";

    // Imprimir el valor actual del arreglo
    print("Valor actual de var: %s\n", var);

    // Reasignar un nuevo valor al arreglo
    strcpy(var, "Nuevo Valor");

    // Imprimir el nuevo valor del arreglo
    print("Nuevo valor de var: %s\n", var);

    return 0;
}
