#include <iostream>

int main() {
	int n, b, h, w, p, a, best, aux;
	std::cin >> n;
	while (std::cin) {
		std::cin >> b >> h >> w;
		best = 500001;
		for (int i = 0; i < h; ++i) {
			std::cin >> p;
			for (int j = 0; j < w; ++j) {
				std::cin >> a;
				if (a >= n) {
					aux = n * p;
					if (aux < best) best = aux;
				}
			}
		}

		if (best <= b) std::cout << best << '\n';
		else std::cout << "stay home\n";

	std::cin >> n;
	}
return 0;
}