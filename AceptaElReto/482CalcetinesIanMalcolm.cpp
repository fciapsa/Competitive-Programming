#include <iostream>

bool resuelve() {
	char c;
	std::cin >> c;

	if (c == '.') return false;

	int n = 0, g = 0;

	if (c == 'N') ++n;
	else ++g;
	std::cin >> c;
	while (c != '.') {
		if (c == 'N') ++n;
		else ++g;
		std::cin >> c;
	}

	if (n % 2 == 0 && g % 2 == 0) std::cout << "EMPAREJADOS\n";
	else if (n % 2 == 0) std::cout << "GRIS SOLITARIO\n";
	else if (g % 2 == 0) std::cout << "NEGRO SOLITARIO\n";
	else std::cout << "PAREJA MIXTA\n";

	return true;
}

int main() {
	while (resuelve());
	return 0;
}