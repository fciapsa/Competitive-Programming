#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, x;
	std::cin >> N;
	while (std::cin) {
		std::vector<int> v1, v2;
		for (int i = 0; i < N; ++i) {
			std::cin >> x;
			v1.push_back(x);
		}
		for (int i = 0; i < N; ++i) {
			std::cin >> x;
			v2.push_back(x);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int i = N-1, j = N-1, sol = 0;
		while (i >= 0) {
			if (v1[i] <= v2[j]) {
				--j;
				++sol;
			}
		--i;
		}
	std::cout << sol << '\n';
	std::cin >> N;
	}

return 0;
}