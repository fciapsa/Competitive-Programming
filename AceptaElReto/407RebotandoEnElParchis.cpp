#include <iostream>

int main() {
	int c, p, t, aux;
	std::cin >> c >> p >> t;
	while (c != 0) {
		aux = p + t;
		if (aux <= c) std::cout << aux << '\n';
		else std::cout << c - aux % c << '\n';
	std::cin >> c >> p >> t;
	}
return 0;
}