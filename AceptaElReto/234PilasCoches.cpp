#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n, N, V;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int c = 0;
		std::cin >> N >> V;
		std::vector<int> v(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> v[i];
		}
		sort(v.begin(), v.end());
		int k = 0; --N;
		while (k < N) {
			if (v[k] + v[N] >= V) {
				++c;
				--N;
			}
			++k;
		}
		std::cout << c << '\n';
	}
}