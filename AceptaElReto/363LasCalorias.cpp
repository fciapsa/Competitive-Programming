#include <iostream>

int main() {
	int e, n, x, tot;
	std::cin >> e;
	while (e != 0) {
		std::cin >> n;
		tot = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> x;
			tot += x;
		}
		if (tot % e == 0) std::cout << tot / e << '\n';
		else std::cout << tot / e + 1 << '\n';

	std::cin >> e;
	}
return 0;
}