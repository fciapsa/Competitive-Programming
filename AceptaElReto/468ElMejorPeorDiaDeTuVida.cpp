#include <iostream>
#include <vector>

int main() {
	int N, max, sol, aux;
	std::cin >> N;
	while (std::cin) {
		std::vector<int> v(N);
		for (int i = 0; i < N; ++i) std::cin >> v[i];

		max = 0;
		sol = 0;
		for (int i = N - 1; i >= 0; --i) {
			if (v[i] > max) max = v[i];
			aux = max - v[i];
			if (aux > sol) sol = aux;
		}

		std::cout << sol << '\n';

	std::cin >> N;
	}
return 0;
}