#include <iostream>
#include <vector>
#include <cstdlib>//abs

int main() {
	bool rep;
	int n, l, r, lc, mindif, aux, bestl, bestr;
	std::cin >> n;
	while (std::cin) {
		l = 0; r = 0;
		rep = false;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> v[i];
			r += v[i];
		}

		mindif = r;
		for (int i = 0; i < n; ++i) {
			l += v[i];
			r -= v[i];
			aux = std::abs(l - r);
			if (aux < mindif) {
				mindif = aux;
				lc = i + 1;
				bestl = l;
				bestr = r;
				rep = false;
			}
			else if (aux == mindif) rep = true;
		}

		if (rep) std::cout << "NO JUEGAN\n";
		else std::cout << lc << ' ' << bestl << ' ' << bestr << '\n';

	std::cin >> n;
	}
return 0;
}