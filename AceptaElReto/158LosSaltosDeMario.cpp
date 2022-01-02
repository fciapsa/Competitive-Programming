#include <iostream>

int main() {
	int T, n, ant, x, up, down;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		up = 0;
		down = 0;
		std::cin >> n >> ant;
		for (int i = 1; i < n; ++i) {
			std::cin >> x;
			if (x > ant) ++up;
			else if (x < ant) ++down;
			ant = x;
		}
		std::cout << up << ' ' << down << '\n';
	}
return 0;
}