#include <iostream>
#include <cstdlib>
#include <cmath>

int leerArbol(bool& equi) {
	char raiz;

	std::cin >> raiz;
	if (raiz == '.') return 0;
	else {
		int b1 = leerArbol(equi);
		int b2 = leerArbol(equi);
		equi = equi && std::abs(b1 - b2) < 2;
		return std::max(b1, b2) + 1;
	}
}

void resuelveCaso() {
	char root;
	std::cin >> root;

	if (root == '.') std::cout << "SI\n";
	else {
		bool equi = true;
		int b1 = leerArbol(equi);
		int b2 = leerArbol(equi);
		if (equi && std::abs(b1 - b2) < 2) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
}

int main() {
	int nc;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		resuelveCaso();
	}
	return 0;
}