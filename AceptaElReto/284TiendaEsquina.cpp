#include <iostream>

int main() {
	int ncasos = 0, cost = 0, paga = 0, cambio = 0, n2e = 0, n1e = 0;
	int n50 = 0, n20 = 0, n10 = 0, n5 = 0, n2 = 0, n1 = 0;
	char b = ' ';

	std::cin >> ncasos;
	for (int i = 0; i < ncasos; ++i) {
		std::cin >> cost >> paga;
		if (paga < cost) std::cout << "DEBE " << cost - paga << '\n';
		else { cambio = paga - cost;
		int resto = 0;
		n2e = cambio / 200;
		resto = cambio % 200;
		n1e = resto/100;
		resto = resto % 100;
		n50 = resto / 50;
		resto = resto % 50;
		n20 = resto / 20;
		resto = resto % 20;
		n10 = resto / 10;
		resto = resto % 10;
		n5 = resto / 5;
		resto = resto % 5;
		n2 = resto / 2;
		resto = resto % 2;
		n1 = resto;
		std::cout << n2e << b << n1e<< b << n50<< b << n20 << b << n10 << b << n5 << b << n2 << b << n1 << '\n';
		}
	}

return 0;
}