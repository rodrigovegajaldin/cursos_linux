#include <cstdio>

void test(){
    static int var = 0;
    printf("1.la variable es : %d\n",var);
    var++;
    printf("2.la variable es : %d\n",var);
}
struct PoderNuclear{
    static int poder_nuclear;
    static void aumentar_poder_nuclear(int isotopos_nucleares){
        poder_nuclear = poder_nuclear + isotopos_nucleares;
        const auto calor_perdido = poder_nuclear * 20;
        if (calor_perdido >10000){
            printf("Advetencias: sobracarga\n");
        }
        printf("poder nuclear: %d\n",poder_nuclear);
    }
};
int PoderNuclear::poder_nuclear =200;

int main(){
    //test();
    //test();
    PoderNuclear::aumentar_poder_nuclear(100);
    PoderNuclear::aumentar_poder_nuclear(500);
    return 0;
}