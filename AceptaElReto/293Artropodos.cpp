#include <iostream>

int main() {
	int nc, a, b, c, d, e;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		std::cin >> a >> b >> c >> d >> e;
		std::cout << 6 * a + 8 * b + 10 * c + d * e * 2 << '\n';
	}
return 0;
}