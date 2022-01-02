#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

int main() {
	int n, q, x, j;
	std::string s;
	std::cin >> n;
	while (n != 0) {
		std::vector<int> cola(n);
		std::unordered_map<int, int> cubiertas;
		for (int i = 0; i < n; ++i) {
			std::cin >> cola[i];
			++cubiertas[cola[i]];
		}

		std::cin >> q;
		for (int i = 0; i < q; ++i) {
			std::cin >> s >> x;
			if (s == "EMBARQUE") {
				if (cubiertas[x] > 0) {
					j = 0;
					for (int k = 0; k < n; ++k) {
						if (cola[k] != x) {
							cola[j] = std::move(cola[k]);
							++j;
						}
					}
					n -= cubiertas[x];
					cubiertas[x] = 0;
				}
				std::cout << n << '\n';
			}
			else std::cout << cola[x - 1] << '\n';
		}
		std::cout << "*\n";
	std::cin >> n;
	}
return 0;
}