#include <iostream>

int sumLong(int l) {
	if (l == 1) return 4;
	else return 4*l + 4 * sumLong(l / 2);
}

bool resuelveCaso() {
	int l;
	std::cin >> l;

	if (!std::cin) return false;

	std::cout << sumLong(l) << '\n';
return true;
}

int main() {
	while (resuelveCaso());
return 0;
}