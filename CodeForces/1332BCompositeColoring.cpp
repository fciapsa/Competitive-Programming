#include <iostream>
#include <vector>
#include <unordered_set>

const std::vector<int> firstP = { 2,3,5,7, 11, 13, 17, 19, 23, 29, 31 };

int main() {
	bool found;
	int T, n, max_c, x, j;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n;
		max_c = 0;
		std::vector<int> sol(n);
		std::vector<int> colores(11, -1);
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			j = 0;
			while (x % firstP[j] != 0)++j;
			if (colores[j] == -1) {
				++max_c;
				colores[j] = max_c;
			}
			sol[i] = colores[j];
		}
		std::cout << max_c << '\n';
 		std::cout << sol[0];
		for (int i = 1; i < n; ++i) std::cout << ' ' << sol[i];
		std::cout << '\n';
	}
return 0;
}