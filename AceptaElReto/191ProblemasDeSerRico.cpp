#include <iostream>

int main() {
	int N;
	std::cin >> N;

	int n, ini, step, minus, sol;
	for (int i = 0; i < N; ++i) {
		std::cin >> n >> ini >> step;
		sol = n * ini;
		minus = step;
		--n;
		for (int j = 0; j < n; ++j) {
			sol -= minus;
			minus += step;
		}
		std::cout << sol << '\n';
	}
return 0;
}