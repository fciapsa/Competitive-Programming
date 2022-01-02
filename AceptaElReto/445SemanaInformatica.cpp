//Flavius Abel Ciapsa

#include <iostream>
#include <vector>
#include <algorithm>

bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (!std::cin) return false;

	std::vector<int> comienzos(N), finales(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> comienzos[i] >> finales[i];
	}

	sort(comienzos.begin(), comienzos.end());
	sort(finales.begin(), finales.end());

	int libres = 0, ocupados = 1;
	int i = 1, j = 0;
	while (i < N && j < N) {
		while (i < N && comienzos[i] < finales[j]) {
			if (libres > 0) --libres;
			++ocupados;
			++i;
		}
		if (i < N) {
			if (comienzos[i] == finales[j]) {
				++i;
				++j;
			}
			else {
				while (j < N && finales[j] < comienzos[i]) {
					--ocupados;
					++libres;
					++j;
				}
			}
		}
	}

	std::cout << libres + ocupados - 1 << '\n';

return true;
}

int main() {
	while (resuelveCaso());
return 0;
}