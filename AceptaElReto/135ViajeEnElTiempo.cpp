#include <iostream>

const int MOD = 999999;

int main() {
	int T, ant, act, k, cambios;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		cambios = 0;
		std::cin >> ant >> act;
		if (act >= ant) k = act - ant;
		else k = MOD + 1 + (act - ant);

		ant = act;
		std::cin >> act;
		while (act != -1) {
			if (ant + k <= MOD) {
				if (act != ant + k) {
					++cambios;
					if (act >= ant) k = act - ant;
					else k = MOD + 1 + (act - ant);
				}
			}
			else {
				if (act != ant + k - MOD - 1) {
					++cambios;
					if (act >= ant) k = act - ant;
					else k = MOD + 1 + (act - ant);
				}
			}

		ant = act;
		std::cin >> act;
		}

		if (ant + k <= MOD) std::cout << cambios << ' ' << ant + k << '\n';
		else std::cout << cambios << ' ' << ant + k - MOD - 1 << '\n';
	}
return 0;
}