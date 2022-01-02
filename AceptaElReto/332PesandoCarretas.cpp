#include <iostream>
#include <vector>

std::vector<int> x(5), s(10);

int main() {
	int T, tot;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		tot = 0;
		for (int i = 0; i < 10; ++i) {
			std::cin >> s[i];
			tot += s[i];
		}
		tot /= 4;

		x[4] = -(tot - s[9] - s[0] - s[1]);
		x[3] = s[0] - x[4];
		x[0] = -(tot - s[0] - s[9] - s[8]);
		x[1] = s[9] - x[0];
		x[2] = tot - x[0] - x[1] - x[3] - x[4];

		std::cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << ' ' << x[4] << '\n';
	}

return 0;
}