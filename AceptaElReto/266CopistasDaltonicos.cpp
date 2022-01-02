#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main() {
	int f, c, cop;
	char c1, c2, act, dest;
	std::cin >> f >> c;
	while (f != 0) {
		std::vector<std::vector<char>> mat(f, std::vector<char>(c));
		std::unordered_map<char, char> cambios;
		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) {
				std::cin >> mat[i][j];
				cambios[mat[i][j]] = mat[i][j];
			}
		}

		std::cin >> cop;
		for (int k = 0; k < cop; ++k) {
			std::cin >> c1 >> c2;
			for (auto it = cambios.begin(); it != cambios.end(); ++it) {
				if (c1 == it->second) it->second = c2;
			}
		}

		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) {
				std::cout << cambios[mat[i][j]];
			}
			std::cout << '\n';
		}

	std::cin >> f >> c;
	}
return 0;
}