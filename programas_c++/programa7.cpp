//este programa prueba el uso del puntero this
#include <cstdio>

class Test{
    private:
        int x;
    public:
        void setX(int x){
            this->x = x;
        }
        void print(){
            printf("x = %d\n", x);
        }
};
class Test2{
    private:
        int x;
        int y;
    public:
        Test2(int x=0, int y=0){
            this->x=x;
            this->y=y;
        }
        Test2& setX(int a){
            x = a;
            return *this;
        }
        Test2& setY(int b){//se utiliza referencias a funcion para poder devolver this
            y = b;
            return *this;
        }
        void print(){
            printf("x=%d\n",x);
            printf("y=%d\n",y);
        }
};
int main(){
    Test obj;
    int x = 20;
    obj.setX(30);
    obj.print();
    printf("x = %d\n",x);
    printf("test2\n");
    Test2 obj2(5,5);
    obj2.print();
    obj2.setX(10).setY(20);//se puede hacer esto gracias a el puntero this
    obj2.print();
    return 0;
}