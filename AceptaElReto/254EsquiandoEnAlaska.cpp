#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;

	while (N != 0) {
		std::vector<int> H(N);
		std::vector<int> L(N);

		for (int i = 0; i < N; ++i) std::cin >> H[i];
		for (int i = 0; i < N; ++i) std::cin >> L[i];

		std::sort(H.begin(), H.end());
		std::sort(L.begin(), L.end());

		int sol = 0;
		for (int i = 0; i < N; ++i) sol += abs(H[i] - L[i]);

		std::cout << sol << '\n';

	std::cin >> N;
	}

return 0;
}
