#include <iostream>
#include <vector>
#include <algorithm>//sort,min
#include <climits>

struct casilla {
	int x, y, val;
	bool operator<(casilla const& other) const {
		return val < other.val;
	}
};

int main() {
	int n, x, min, movs;
	casilla ini;
	bool ok;
	std::cin >> n;
	while (n != 0) {
		std::vector<std::vector<casilla>> diags(n);//diagonales toroidales
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				std::cin >> x;
				diags[(n + i - j) % n].push_back({ i,j,x });
			}
		}

		for (int i = 0; i < n; ++i) sort(diags[i].begin(), diags[i].end());
		//comprobar que es estrictamente creciente y son posiciones consecutivas
		min = INT_MAX;
		for (int i = 0; i < n; ++i) {
			casilla ini = diags[i][0];
			ok = true;
			for (int j = 1; j < n && ok; ++j) {
				if (diags[i][j - 1].x == n - 1) {
					if (diags[i][j].x != 0) ok = false;
				}
				else if (diags[i][j].x != diags[i][j - 1].x + 1) ok = false;

				if (diags[i][j].val == diags[i][j - 1].val) ok = false;
			}

			if (ok) {
				movs = std::min(ini.x, n - ini.x) + std::min(ini.y, n - ini.y);
				if (movs < min) min = movs;
			}
		}

		if (min != INT_MAX) std::cout << min << '\n';
		else std::cout << "IMPOSIBLE\n";
	std::cin >> n;
	}
return 0;
}