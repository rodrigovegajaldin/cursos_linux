//este programa prueba el uso de punteros y referencias 
#include <cstdio>

struct Element {
        Element* next{};
        void insert_after(Element*  new_element){
            new_element->next = next;
            next = new_element;
        }
        char prefix[2];
        short operating_number;
};
int main(){
        Element trooper1, trooper2, trooper3,trooper4;
        trooper1.prefix[0] = 'f';
        trooper1.prefix[1] = 'k';
        trooper1.operating_number = 321;
        trooper1.insert_after(&trooper2);
        printf("trooper1: %p trooper2: %p trooper3: %p troper4: %p\n",trooper1.next,trooper2.next,trooper3.next,trooper4.next);
        trooper2.prefix[0] = 'r';
        trooper2.prefix[1] = 'v';
        trooper2.operating_number = 123;
        trooper2.insert_after(&trooper3);
        printf("trooper1: %p trooper2: %p trooper3: %p troper4: %p\n",trooper1.next,trooper2.next,trooper3.next,trooper4.next);
        trooper3.prefix[0] = 'm';
        trooper3.prefix[1] = 'j';
        trooper3.operating_number = 005;
        trooper3.insert_after(&trooper4);
        printf("trooper1: %p trooper2: %p trooper3: %p troper4: %p\n",trooper1.next,trooper2.next,trooper3.next,trooper4.next);
        trooper4.prefix[0] = 'a';
        trooper4.prefix[1] = 'v';
        trooper4.operating_number = 124;
        printf("trooper1: %p trooper2: %p trooper3: %p troper4: %p\n",trooper1.next,trooper2.next,trooper3.next,trooper4.next);


        for (Element* cursor = &trooper1; cursor; cursor = cursor->next){//aqui se pone como condicion solo cursor para CORROBORAR QUE NO SEA NULL 
            printf("stormtropper rodri %c%c-%d\n",
            cursor->prefix[0],
            cursor->prefix[1],
            cursor->operating_number);
        }
	return 0;
}
