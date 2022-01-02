#include <iostream>

int main() {
	int T, h, w;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> h >> w;
		h *= w;
		if (h % 2 == 0) {
			h /= 2;
			std::cout << h << ' ' << h << '\n';
		}
		else {
			h /= 2;
			std::cout << h + 1 << ' ' << h << '\n';
		}

	}
return 0;
}