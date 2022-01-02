#include <iostream>

int leerArbol() {
	int hijos;
	std::cin >> hijos;

	if (hijos == 0) return 1;
	else {
		int max = 0, act = 0;
		for (int i = 0; i < hijos; ++i) {
			act = leerArbol();
			if (act > max) max = act;
		}
		return 1 + max;
	}
}

int main() {
	int nc;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		int h = leerArbol();
		std::cout << h << '\n';
	}
	return 0;
}