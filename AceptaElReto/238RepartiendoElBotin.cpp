#include <iostream>
#include <vector>

int main() {
	int b, n, aux, j;
	std::cin >> b >> n;
	while (b != 0) {
		std::vector<std::vector<int>> v(n);
		std::vector<int> sums(n, 0);
		j = 0;
		for (int i = 0; i < b; ++i) {
			if (j == n) j = 0;
			std::cin >> aux;
			v[j].push_back(aux);
			sums[j] += aux;
			++j;
		}

		for (int i = 0; i < n; ++i) {
			std::cout << sums[i] << ':';
			for (int k = 0; k < v[i].size(); ++k) std::cout << ' ' << v[i][k];
			std::cout << '\n';
		}
		std::cout << "---\n";
	std::cin >> b >> n;
	}
return 0;
}
