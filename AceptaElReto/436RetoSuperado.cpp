#include <iostream>

bool resuelve() {
	long long int g, h;
	std::cin >> g >> h;

	if (!std::cin) return false;

	h *= 1000000;
	int i = 0;
	while (g <= h) {
		++i;
		g *= 2;
	}

	std::cout << i << '\n';
return true;
}

int main() {
	while (resuelve());
return 0;
}