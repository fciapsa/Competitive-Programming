#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int main() {
	int molinos = 0, energ = 0, consultas = 0, m1 = 0, m2 = 0;

	std::cin >> molinos;
	while (molinos != 0) {
		std::vector<int> energias(molinos + 1, 0);
		int acumul = 0;
		for (int i = 1; i < molinos + 1; ++i) {
			std::cin >> energ;
			acumul += energ;
			energias[i] = acumul;
		}

		std::cin >> consultas;
		for (int j = 0; j < consultas; ++j) {
			int sol = 0;
			std::cin >> m1 >> m2;
			sol = energias[m2] - energias[m1 -1];
			std::cout << sol << '\n';
		}
	std::cin >> molinos;
	}
    return 0;
}