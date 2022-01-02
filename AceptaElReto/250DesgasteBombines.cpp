#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
	int d;
	std::cin >> d;
	while (d != 0) {
		std::vector<int> v(d);
		int sol = 0, sum1 = 0, sum2 = 0;
		for (int i = 0; i < d; ++i) {
			std::cin >> v[i];
			sum1 += v[i];
		}

		int min = abs(sum1);
		for (int i = 0; i < d; ++i) {
			sum2 += v[i];
			sum1 -= v[i];
			if (abs(sum1 - sum2) < min) {
				min = abs(sum1 - sum2);
				sol = i + 1;
			}
		}
		std::cout << sol << '\n';
	std::cin >> d;
	}
return 0;
}