#include <iostream>
#include <vector>
#include <algorithm>

const int TAM = 8, SUMA_MAX = 10000000;

int numDigitos(long long int n) {
	int sol = 0;
	while (n > 0) {
		++sol;
		n /= 10;
	}
return sol;
}

int main() {
	std::vector<long long int> v(TAM);
	long long int aux;
	bool crece;
	int zipi, zape, numDig;
	
	std::cin >> v[0];
	while (v[0] != 0) {
		for (int i = 1; i < TAM; ++i) std::cin >> v[i];

		std::vector<int> cambios;
		for (int i = 0; i < TAM; ++i) {
			numDig = numDigitos(v[i]);

			aux = 1;
			while (numDig > 0) {
				aux *= 10;
				--numDig;
			}

			while (aux - v[i] <= SUMA_MAX) {
				cambios.push_back(aux - v[i]);
				aux *= 10;
			}
		}

		sort(cambios.begin(), cambios.end());
		zipi = 0;
		zape = 0;
		if (cambios.size() > 0) {
			if (cambios[0] % 2 == 0) {
				std::cout << "Zape: " << cambios[0] << '\n';
				++zape;
			}
			else {
				std::cout << "Zipi: " << cambios[0] << '\n';
				++zipi;
			}
		}
		for (int i = 1; i < cambios.size(); ++i) {
			if (cambios[i] != cambios[i-1]) {
				if (cambios[i] % 2 == 0) {
					std::cout << "Zape: " << cambios[i] << '\n';
					++zape;
				}
				else {
					std::cout << "Zipi: " << cambios[i] << '\n';
					++zipi;
				}
			}
		}

		std::cout << "Resultado final: Zipi: " << zipi << " Zape: " << zape << '\n';

	std::cin >> v[0];
	}
return 0;
}