OBJS = main.o salida.o calculadora.o
BINARY = programa
x = Hola
y = ${x} Adios
CFLAGS = -g -Wall

all: programa clean

programa: ${OBJS}
	gcc -o ${BINARY} ${OBJS}

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f ${BINARY} ${OBJS}

imprimir:
	@echo ${x} #poner el arroba al inicio hace que no se imprima el comando cuando se ejecuta
	echo ${y}	
