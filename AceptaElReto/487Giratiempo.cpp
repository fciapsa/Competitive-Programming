#include <iostream>

int main() {
	int nc;
	std::cin >> nc;

	for (int i = 0; i < nc; ++i) {
		long long int N;
		std::cin >> N;

		long long int q = N / 3600;
		long long int acum = q;
		long long int aux = N%3600;
		while (aux+q >= 3600) {
			aux += q;
			q = aux / 3600;
			acum += q;
			aux = aux % 3600;
		}
		long long int sol = N + acum;
		if (sol % 3600 == 0) ++sol;
		std::cout << sol << '\n';
	}

	return 0;
}