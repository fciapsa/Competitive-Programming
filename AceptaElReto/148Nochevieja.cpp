#include <iostream>

bool resuelve() {
	int hh, mm; char aux;
	std::cin >> hh >> aux >> mm;

	if (hh == 0 && mm == 0) return false;

	if (mm == 0) std::cout << 60 * (24 - hh) << '\n';
	else std::cout << 60 * (24 - hh - 1) + 60 - mm << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}