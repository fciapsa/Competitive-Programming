#include <iostream>

int main() {
	int T, C, x, acum, ind, sol;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> C;
		C *= 8;

		sol = -1;
		ind = 1;
		acum = 0;
		std::cin >> x;
		while (x != 0) {
			acum += x;
			if (sol == -1 && acum >= C) {
				sol = ind;
			}
			std::cin >> x;
			++ind;
		}

		if (sol != -1) std::cout << sol << '\n';
		else std::cout << "SIGAMOS RECICLANDO\n";
	}
return 0;
}