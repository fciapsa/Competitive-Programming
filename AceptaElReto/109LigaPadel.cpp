#include <iostream>
#include <string>
#include <unordered_map>

int main() {
	std::ios::sync_with_stdio(false);

	std::string categ;
	std::cin >> categ;

	std::string eq1, eq2, ganador;
	int res1, res2, jugados, max;
	bool empate;
	while (categ != "FIN") {
		jugados = 0;
		empate = false;
		max = -1;
		std::unordered_map<std::string, int> tabla;

		std::cin >> eq1;
		while (eq1 != "FIN") {
			std::cin >> res1 >> eq2 >> res2;
			++jugados;

			if (res1 > res2) {
				tabla[eq1] += 2;
				tabla[eq2] += 1;
			}
			else {
				tabla[eq1] += 1;
				tabla[eq2] += 2;
			}

			if (tabla[eq1] > max) {
				max = tabla[eq1];
				ganador = eq1;
				empate = false;
			}
			else if (tabla[eq1] == max) empate = true;

			if (tabla[eq2] > max) {
				max = tabla[eq2];
				ganador = eq2;
				empate = false;
			}
			else if (tabla[eq2] == max) empate = true;


		std::cin >> eq1;
		}
		
		if (empate) std::cout << "EMPATE";
		else std::cout << ganador;
		std::cout << ' ' << tabla.size() * (tabla.size() - 1) - jugados << '\n';

	std::cin >> categ;
	}


return 0;
}