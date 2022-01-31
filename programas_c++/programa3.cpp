#include <cstdio>

struct Hucha{
	private:
		int moneda;
	public:
		Hucha(){
			moneda = 200;
		}//este es el conructor del objeto
		void add_moneda(){
			moneda++;
		}
		bool set_moneda(int nuevo_moneda){
			if (nuevo_moneda < 200) return false;
				moneda = nuevo_moneda;
			return true;
		}
		int get_moneda(){
			return moneda;
		}
};

int main(){
	Hucha miHucha;
	Hucha miHucha2;

	printf("Monedas: %d\n",miHucha.get_moneda());
	printf("Monedas 2: %d\n",miHucha2.get_moneda());

	Hucha miHucha3;
	Hucha* miHucha3_direcc = &miHucha3;
	miHucha3_direcc->set_moneda(300);
	miHucha3_direcc->add_moneda();//con esto accedemos al valor de miHucha3 y usamos la funcion add_mine
	printf("Monedas en Hucha3: %d\n",miHucha3_direcc->get_moneda());
	return 0;
	
}
