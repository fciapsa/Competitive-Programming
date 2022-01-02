#include <iostream>

int main() {
	int n, k, sol, act, under, x;
	std::cin >> n >> k;
	while (n != 0) {
		sol = 0;
		act = 0;
		under = -1;
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			if (x == 1) {
				under = 0;
				++act;
				if (act > sol) sol = act;
			}
			else {
				if (under != -1) {
					++under;
					++act;
				}
				if (under > k) {
					under = -1;
					act = 0;
				}
			}
		}
		std::cout << sol << '\n';
		std::cin >> n >> k;
	}
	return 0;
}