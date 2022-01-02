#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int M, N, x, y;//M es tam, N es num de reinas
	bool b = false;
	std::cin >> M >> N;
	while (M != 0 || N != 0) {
		b = false;
		std::vector<bool> f(M, true), c(M, true), d1(2 * M - 1, true), d2(2 * M - 1, true);
		int i = 0;
		while(i < N && !b) {
			std::cin >> x >> y;
			--x;
			--y;

			if (c[x]) c[x] = false;
			else b = true;

			if (f[y]) f[y] = false;
			else b = true;

			if (x - y >= 0 && d1[x - y]) d1[x - y] = false;
			else if (x - y < 0 && d1[M - 1 + y-x]) d1[M - 1 + y-x] = false;
			else b = true;

			if (d2[x + y]) d2[x + y] = false;
			else b = true;

		++i;
		}
		while (i < N) {
			std::cin >> x >> y;
			++i;
		}

		if (b) std::cout << "SI\n";
		else std::cout << "NO\n";

	std::cin >> M >> N;
	}

return 0;
}