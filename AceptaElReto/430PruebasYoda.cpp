#include <iostream>
#include <vector>

int main(){
	int pruebas = 0;
	std::cin >> pruebas;
	while (pruebas != 0){
		int inicio, periodo;
		std::cin >> inicio >> periodo;
		int necesito = inicio;
		for (int i = 1; i < pruebas; ++i) {
			std::cin >> inicio >> periodo;
			if (necesito < inicio) necesito = inicio;
			else if ((necesito - inicio) % periodo != 0) necesito += periodo - (necesito - inicio) % periodo;
			else necesito += periodo;
		}
	std::cout << necesito << '\n';
	std::cin >> pruebas;
	}
return 0;
}