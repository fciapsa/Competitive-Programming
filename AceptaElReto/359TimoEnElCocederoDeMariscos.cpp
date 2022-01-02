#include <iostream>

int main() {
	int T, x, cont, n;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		cont = 0;
		n = 0;
		std::cin >> x;
		while (x != -1) {
			cont += x;
			++n;
		std::cin >> x;
		}

		if (cont > n) std::cout << "Suerte\n";
		else if (cont == n) std::cout << "Justo\n";
		else std::cout << "Timo\n";

	}
return 0;
}