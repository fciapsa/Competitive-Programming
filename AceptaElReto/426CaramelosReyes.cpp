#include <iostream>

bool resuelveCaso() {
	int x, tot;
	std::cin >> x;

	if (x == 0) return false;

	int cont = 1;
	tot = x;
	std::cin >> x;
	while (x != 0) {
		++cont;
		tot += x;
		std::cin >> x;
	}

	if (tot%cont == 0) std::cout << "REPARTO JUSTO\n";
	else std::cout << "IMPOSIBLE\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}