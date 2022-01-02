#include <iostream>

bool resuelve() {
	int v, t;
	std::cin >> v >> t;

	if (!std::cin) return false;

	std::cout << 2 * v * t << '\n';
return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	while (resuelve());
return 0;
}