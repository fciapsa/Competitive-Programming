#include <iostream>
#include <cmath>

int main() {
	int T, i, p, dif;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> i >> p;

		if (i < p) dif = p - i;
		else dif = i - p;

		if (dif == 0 || dif == 180 || dif == 360) std::cout << "DA IGUAL\n";
		else if (dif < 180) {
			if (i < p) std::cout << "ASCENDENTE\n";
			else std::cout << "DESCENDENTE\n";
		}
		else {
			if (i < p) std::cout << "DESCENDENTE\n";
			else std::cout << "ASCENDENTE\n";
		}

	}
	return 0;
}