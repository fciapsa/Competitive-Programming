#include <iostream>

int main() {
	int T, n,x, ini_max, fin_max, ini, fin, max;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n;
		max = 0;
		ini = -1;
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			if (x != 0) {
				if (ini == -1) {
					ini = i;
					fin = i;
				}
				else ++fin;
				if (fin - ini + 1 > max) {
					max = fin - ini + 1;
					ini_max = ini;
					fin_max = fin;
				}
			}
			else ini = -1;
		}

		if (max == 0) std::cout << "SIGUE BUSCANDO\n";
		else std::cout << max << " -> [" << ini_max << ',' << fin_max << "]\n";
	}
return 0;
}