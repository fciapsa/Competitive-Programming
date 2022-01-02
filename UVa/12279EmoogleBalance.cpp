#include <iostream>

int main() {
	int n, cont, x, k = 1;
	std::cin >> n;
	while (n != 0) {
		cont = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			if (x != 0) ++cont;
			else --cont;
		}
		std::cout << "Case " << k << ": " << cont << '\n';
	++k;
	std::cin >> n;
	}
return 0;
}