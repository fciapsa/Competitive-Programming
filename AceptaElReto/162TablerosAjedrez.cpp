#include <iostream>
#include <string>
#include <iomanip>

int main() {
	int n; char c;
	std::cin >> n;
	while (n != 0) {
		int d = 2 * n; //el doble del tam
		std::cin >> c; //relleno de las casillas oscuras
		int tam = 8 * n;

		//Borde sup
		std::cout << '|';
		std::cout << std::setw(tam) << std::setfill('-') << "-";
		std::cout << "|\n";

		//Obtener fila par
		std::string fp = "";
		fp += '|';
		
		for (int i = 0; i < tam; ++i) {
			if (i % d < n) fp += ' ';
			else fp += c;
		}
		fp += '|';

		//Obtener fila impar
		std::string fi = "";
		fi += '|';
		for (int i = 0; i < tam; ++i) {
			if (i % d < n) fi += c;
			else fi += ' ';
		}
		fi += '|';

		//Interior
		for (int i = 0; i < tam; ++i) {
			if (i % d < n) std::cout << fp << '\n';
			else std::cout << fi << '\n';
		}

		//Borde inf
		std::cout << '|';
		std::cout << std::setw(tam) << std::setfill('-') << "-";
		std::cout << "|\n";
		

		std::cin >> n;
	}
return 0;
}