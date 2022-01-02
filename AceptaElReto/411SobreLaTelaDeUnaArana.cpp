#include <iostream>

int main() {
	long long int max, x, acum, cont;
	std::cin >> max;
	while (max != 0) {
		acum = 0;
		cont = 0;

		std::cin >> x;
		while (x != 0) {
			acum += x;
			if (acum <= max) ++cont;
			std::cin >> x;
		}

		std::cout << cont << '\n';

	std::cin >> max;
	}
return 0;
}