#include <iostream>

int main() {
	int n, aux;
	std::cin >> n;
	while (n != 0) {
		aux = n;
		while (aux >= 10) {
			n = aux;
			aux = 0;
			while (n > 0) {
				aux += (n % 10);
				n /= 10;
			}
		}
		std::cout << aux << '\n';
	std::cin >> n;
	}
	return 0;
}