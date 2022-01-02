#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, aux, max;
	std::cin >> N;
	while (N != 0) {
		std::vector<int> v(N);
		for (int i = 0; i < N; ++i)std::cin >> v[i];
		sort(v.begin(), v.end());
		max = 0;
		for (int i = 0; i < N; i += 2) {
			aux = v[i + 1] - v[i];
			if (aux > max) max = aux;
		}

		std::cout << max << '\n';
	std::cin >> N;
	}
return 0;
}