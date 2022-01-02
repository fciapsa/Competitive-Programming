#include <iostream>

int main() {
	int t, n, x1, x2, h, l, k = 0;
	std::cin >> t;
	while (t--) {
		++k;
		std::cin >> n;
		h = 0;
		l = 0;
		std::cin >> x1;
		while (--n) {
			std::cin >> x2;
			if (x2 > x1) ++h;
			else if (x2 < x1) ++l;

			x1 = x2;
		}

		std::cout << "Case " << k << ": " << h << ' ' << l << '\n';
	}
return 0;
}