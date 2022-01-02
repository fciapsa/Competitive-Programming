#include <iostream>

int main() {
	int nc;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		int N;
		std::cin >> N;
		
		bool pares = true;
		int j = 0, x, w;
		while (j < N && pares) {
			std::cin >> x;
			if (x % 2 != 0) pares = false;
			++j;
		}
		if (pares) w = j;
		else w = j-1;
		bool ok = true;
		while (j < N && ok) {
			std::cin >> x;
			if (x % 2 == 0) ok = false;
			++j;
		}
		//consumir entrada si queda
		while (j < N) {
			std::cin >> x;
			++j;
		}

		if (ok) std::cout << "SI " << w << '\n';
		else std::cout << "NO\n";
	}

	return 0;
}