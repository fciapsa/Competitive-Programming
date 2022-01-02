#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int F, n, midi, x, max, aux;
	std::cin >> F;
	while (F != 0) {
		std::vector<int> v(F);
		for (int i = 0; i < F; ++i) {
			std::cin >> n >> midi >> x;
			max = midi * x;
			for (int j = 1; j < n; ++j) {
				std::cin >> x;
				aux = midi * x;
				if (aux > max) max = aux;
			}

			v[i] = max;
		}

		sort(v.rbegin(), v.rend());
		std::cout << v[0];
		for (int i = 1; i < F; ++i) std::cout << ' ' << v[i];
		std::cout << '\n';

	std::cin >> F;
	}
return 0;
}