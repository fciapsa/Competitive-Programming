#include <iostream>
#include <vector>

int main() {
	int nc, d, m, falta;
	std::cin >> nc;
	std::vector<int> v = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	for (int i = 0; i < nc; ++i) {
		falta = 0;
		std::cin >> d >> m;

		falta += v[m - 1] - d;
		for (int i = m; i < 12; ++i) {
			falta += v[i];
		}
	std::cout << falta << '\n';
	}
return 0;
}