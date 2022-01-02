#include <iostream>
#include <vector>

int main() {
	int n, x, y, sol, aux;
	std::cin >> n;
	while (n != 0) {
		std::vector<int> vx(n), vy(n);
		for (int i = 0; i < n; ++i) std::cin >> vx[i] >> vy[i];
		sol = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (vx[i] > vx[j]) aux = (vx[i] - vx[j]);
				else aux = (vx[j] - vx[i]);

				if (vy[i] > vy[j]) aux += (vy[i] - vy[j]);
				else aux += (vy[j] - vy[i]);

				if (aux > sol) sol = aux;
			}
		}
		std::cout << sol << '\n';
	std::cin >> n;
	}
return 0;
}