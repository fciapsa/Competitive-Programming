#include <iostream>

int leerArbol() {
	char raiz;
	std::cin >> raiz;

	if (raiz == '.') return 0;
	
	int iz = leerArbol();
	int der = leerArbol();
	if (iz > der) return 1 + iz;
	return 1 + der;
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		std::cout << leerArbol() << '\n';
	}
return 0;
}