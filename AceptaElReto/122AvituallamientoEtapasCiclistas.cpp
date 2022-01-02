#include <iostream>

bool resuelveCaso() {
	int x, y, i = 0, ini;
	std::cin >> x;
	if (x == -1) return false;

	int now = 0, max = 0;

	while (x != -1) {
		std::cin >> y;
		if (y == x) ++now;
		else now = 0;
		if (now > max) {
			max = now;
			ini = i + 1 - max;
		}
		x = y;
		++i;
	}

	if (max == 0) std::cout << "HOY NO COMEN\n";
	else std::cout << ini << ' ' << max << '\n';
return true;
}

int main() {
	while (resuelveCaso());
return 0;
}