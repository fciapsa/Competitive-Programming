#include <iostream>
#include <cmath>//abs

int main() {
	int ini, x1, x2, sol;
	std::cin >> ini;
	while (ini >= 0) {
		sol = 0;
		std::cin >> x1;
		while (x1 != -1) {
			std::cin >> x2;
			sol += std::abs(ini - x1) + std::abs(x1 - x2);
			ini = x2;
			std::cin >> x1;
		}
		std::cout << sol << '\n';

	std::cin >> ini;
	}
return 0;
}