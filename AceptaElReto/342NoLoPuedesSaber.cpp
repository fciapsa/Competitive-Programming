#include <iostream>

int main() {
	int ini, fin, n, q, k;
	std::cin >> ini >> fin >> n;
	while (ini != 0) {
		++fin;
		std::cin >> q;
		for (int i = 0; i < q; ++i) {
			std::cin >> k;
			if (n < k) {
				if (k < fin) fin = k;
			}
			else {
				if (k > ini) ini = k;
			}
		}

		if (fin - 1 == ini) std::cout << "LO SABE\n";
		else std::cout << "NO LO SABE\n";


	std::cin >> ini >> fin >> n;
	}
return 0;
}