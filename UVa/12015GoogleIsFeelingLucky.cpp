#include <iostream>
#include <vector>
#include <string>

int main() {
	int t, x, max, k = 0;
	std::vector<std::string> vs(10);
	std::vector<int> vv(10);
	std::cin >> t;
	while (t--) {
		++k;
		max = 0;
		for (int i = 0; i < 10; ++i) {
			std::cin >> vs[i] >> vv[i];
			if (vv[i] > max) max = vv[i];
		}

		std::cout << "Case #" << k << ":\n";
		for (int i = 0; i < 10; ++i) {
			if (vv[i] == max) std::cout << vs[i] << '\n';
		}
	}
	return 0;
}