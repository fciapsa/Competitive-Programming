#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, P, i, j, sol;
	std::cin >> P >> N;
	while (N != 0) {
		std::vector<int> pesos(N);
		for (int i = 0; i < N; ++i) std::cin >> pesos[i];
		sort(pesos.begin(), pesos.end());

		i = 0;
		j = N - 1;
		sol = 0;
		while (i <= j) {
			if (i == j) ++i;
			else {
				if (pesos[i] + pesos[j] <= P) {
					++i;
					--j;
				}
				else --j;
			}
			++sol;
		}
		std::cout << sol << '\n';
	std::cin >> P >> N;
	}
return 0;
}