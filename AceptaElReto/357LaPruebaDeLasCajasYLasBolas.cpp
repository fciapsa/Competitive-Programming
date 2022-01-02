#include <iostream>

int main() {
	int x, ans;
	std::cin >> x;
	while (std::cin) {
		ans = 0;
		while (x > 0) {
			x /= 2;
			++ans;
		}

		std::cout << ans << '\n';

	std::cin >> x;
	}

return 0;
}