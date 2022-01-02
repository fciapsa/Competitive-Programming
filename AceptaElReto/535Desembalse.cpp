#include <iostream>
#include <vector>

int main() {
	int D, sol, max;
	std::cin >> D;
	while (D != 0) {
		std::vector<int> v(D);
		for (int i = 0; i < D; ++i) std::cin >> v[i];
		--D;
		sol = 0;
		max = v[D];
		for (int i = 0; i < D; ++i) {
			sol += (max - v[i]);
		}

		std::cout << sol << '\n';
	std::cin >> D;
	}
return 0;
}