#include <iostream>

int main() {
	bool h;
	int n, aux;
	std::cin >> n;
	while (n >= 0) {
		h = true;
		while (n > 0 && h) {
			aux = n % 10;
			h = aux % 2 == 0;
			n /= 10;
		}
		if (h) std::cout << "SI\n";
		else std::cout << "NO\n";
		std::cin >> n;
	}
return 0;
}