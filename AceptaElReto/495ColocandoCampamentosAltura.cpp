#include <iostream>
#include <vector>
#include <climits>

int main() {
	int N, max, aux_min, j, tope;
	std::cin >> N;
	while (std::cin) {
		std::vector<int> alturas(N + 1), c(N+1), hasta(N + 1);
		for (int i = 1; i <= N; ++i)std::cin >> alturas[i];
		for (int i = 1; i <= N; ++i) std::cin >> c[i];
		std::cin >> max;

		j = 1;
		for (int i = 0; i < N; ++i) {
			while (j + 1 <= N && alturas[j+1] <= alturas[i] + max) ++j;
			hasta[i] = j;
		}
		hasta[N] = N;

		std::vector<int> costes(N + 1);
		j = N;
		while (j >= 0 && hasta[j] == N) {
			costes[j] = c[j];
			--j;
		}
		while (j >= 0) {
			aux_min = INT_MAX;
			tope = hasta[j];
			for (int i = j + 1; i <= tope; ++i) {
				if (costes[i] < aux_min) aux_min = costes[i];
			}
			costes[j] = aux_min + c[j];
		--j;
		}

		std::cout << costes[0] << '\n';
	std::cin >> N;
	}
return 0;
}