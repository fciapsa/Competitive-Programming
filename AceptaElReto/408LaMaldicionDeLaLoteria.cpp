#include <iostream>

int main() {
	int T;
	int p, d, s, m, meses, semanas, dias;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> p >> d >> s >> m;
		meses = 0;
		semanas = 0;
		dias = 0;

		if (p > m) {
			meses = p / m;
			if (p % m == 0) {
				--meses;
				p = m;
			}
			else p %= m;
		}
		if (p > s) {
			semanas = p / s;
			if (p % s == 0) {
				--semanas;
				p = s;
			}
			else p %= s;
		}

		dias = p / d;
		p %= d;
		if (p > 0) ++dias;

		std::cout << meses << ' ' << semanas << ' ' << dias << '\n';
	}
	return 0;
}