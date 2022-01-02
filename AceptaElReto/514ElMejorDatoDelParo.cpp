#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	std::cin >> N;
	long int x, min, cont;

	while (N != 0) {
		std::vector<long int> v(N);
		std::cin >> v[0];
		min = v[0];
		std::cout << 0;
		for (long int i = 1; i < N; ++i) {
			std::cin >> v[i];
			if (v[i] < min) {
				std::cout << ' ' << i;
				min = v[i];
			}
			else {
				cont = 0;
				int j = i - 1;
				while (j > 0 && v[j] > v[i]) {
					++cont;
					--j;
				}
				std::cout << ' ' << cont;
			}
		}
		std::cout << '\n';

		std::cin >> N;
	}
	return 0;
}