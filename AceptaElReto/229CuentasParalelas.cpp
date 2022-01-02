#include <iostream>
#include <vector>

int main() {
	int n, sum1, sum2, sol;
	std::cin >> n;
	while (n != 0) {
		sum1 = 0;
		sum2 = 0;
		sol = 0;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> v[i];
			sum2 += v[i];
		}

		if (sum1 == sum2) ++sol;
		for (int i = 0; i < n; ++i) {
			sum1 += v[i];
			sum2 -= v[i];
			if (sum1 == sum2) ++sol;
		}
		std::cout << sol << '\n';
	std::cin >> n;
	}
return 0;
}