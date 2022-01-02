#include <iostream>

int main() {
	int n, x, max, tot;
	std::cin >> n;
	while (n != 0) {
		std::cin >> tot;
		max = tot;
		for (int i = 1; i < n; ++i) {
			std::cin >> x;
			tot += x;
			if (tot > max) max = tot;
		}
		std::cout << tot << ' ' << max << '\n';
	std::cin >> n;
	}
return 0;
}