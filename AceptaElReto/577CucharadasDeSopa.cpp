#include <iostream>
#include <algorithm>//min

int main() {
	int T, a, b, n;
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b >> n;
		std::cout << std::min(n - a + 1, b + 1) << '\n';
	}
	return 0;
}