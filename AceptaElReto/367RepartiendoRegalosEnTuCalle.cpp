#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>//abs

int main() {
	bool first;
	int T, p, n, x, aux1, aux2, i1, i2;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> p >> n;
		std::vector<int> menores, mayores;
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			if (x <= p) menores.push_back(x);
			else mayores.push_back(x);
		}

		sort(menores.begin(), menores.end());
		sort(mayores.begin(), mayores.end());

		i1 = menores.size() - 1;
		i2 = 0;
		first = true;
		while (i1 >= 0 && i2 < mayores.size()) {
			aux1 = p - menores[i1];
			aux2 = mayores[i2] - p;
			if (aux1 < aux2) {
				if (first) {
					std::cout << menores[i1];
					first = false;
				}
				else std::cout << ' ' << menores[i1];
				p = menores[i1];
				--i1;
			}
			else {
				if (first) {
					std::cout << mayores[i2];
					first = false;
				}
				else std::cout << ' ' << mayores[i2];
				p = mayores[i2];
				++i2;
			}
		}
		while (i1 >= 0) {
			if (first) {
				std::cout << menores[i1];
				first = false;
			}
			else std::cout << ' ' << menores[i1];
			--i1;
		}
		while (i2 < mayores.size()) {
			if (first) {
				std::cout << mayores[i2];
				first = false;
			}
			else std::cout << ' ' << mayores[i2];
			++i2;
		}

		std::cout << '\n';
	}
return 0;
}