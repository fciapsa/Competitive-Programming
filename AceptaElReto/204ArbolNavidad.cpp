#include <iostream>
#include <cstdlib>

int leerArbol(bool &equi) {
	char raiz;

	std::cin >> raiz;
	if (raiz == '.') return 0; //hoja vacia
	else if (raiz == '*') return 1; //hoja adornada
	else { // leer recursivamente los hijos
		int b1 = leerArbol(equi);
		int b2 = leerArbol(equi);
		equi = equi && std::abs(b1 - b2) < 2;
		return b1 + b2;
	}
}

bool resuelveCaso() {
	char root;
	std::cin >> root;

	if (!std::cin) return false;

	if (root == '*' || root == '.') std::cout << "OK\n";
	else {
		bool equi = true;
		int b1 = leerArbol(equi);
		int b2 = leerArbol(equi);
		if (equi && std::abs(b1-b2) < 2) std::cout << "OK\n";
		else std::cout << "KO\n";
	}

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}