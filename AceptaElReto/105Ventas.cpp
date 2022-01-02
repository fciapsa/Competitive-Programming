#include <iostream>

int main() {
	double x,sum, min, max;
	int dia1, dia2;
	bool empate1, empate2;
	std::cin >> x;
	while (x != -1) {
		min = x;
		max = x;
		dia1 = 0;
		dia2 = 0;
		empate1 = false;
		empate2 = false;
		sum = x;
		for (int i = 1; i < 6; ++i) {
			std::cin >> x;
			sum += x;
			if (x < min) {
				min = x;
				empate1 = false;
				dia1 = i;
			}
			else if (x == min) empate1 = true;
			if (x > max) {
				max = x;
				empate2 = false;
				dia2 = i;
			}
			else if (x == max) empate2 = true;
		}

		if (empate2) std::cout << "EMPATE ";
		else {
			switch (dia2) {
			case 0: std::cout << "MARTES "; break;
			case 1: std::cout << "MIERCOLES "; break;
			case 2: std::cout << "JUEVES "; break;
			case 3: std::cout << "VIERNES "; break;
			case 4: std::cout << "SABADO "; break;
			case 5: std::cout << "DOMINGO "; break;
			}
		}
		if (empate1) std::cout << "EMPATE ";
		else {
			switch (dia1) {
			case 0: std::cout << "MARTES "; break;
			case 1: std::cout << "MIERCOLES "; break;
			case 2: std::cout << "JUEVES "; break;
			case 3: std::cout << "VIERNES "; break;
			case 4: std::cout << "SABADO "; break;
			case 5: std::cout << "DOMINGO "; break;
			}
		}
		if (x > sum / 6) std::cout << "SI\n";
		else std::cout << "NO\n";
	std::cin >> x;
	}
return 0;
}