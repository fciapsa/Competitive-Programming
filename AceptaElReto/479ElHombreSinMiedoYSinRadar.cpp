#include <iostream>
#include <string>
#include <vector>

int main() {
	int F, C, N, x, y;
	bool found;
	std::string dir;
	std::cin >> F >> C;
	while (F != 0) {
		std::vector<std::string> mat(F);
		for (int i = 0; i < F; ++i) std::cin >> mat[i];

		std::cin >> N;
		for (int k = 0; k < N; ++k) {
			std::cin >> x >> y >> dir;
			--x;
			--y;
			found = false;
			if (dir == "ARRIBA") {
				for (int i = x - 1; i >= 0 && !found; --i) {
					if (mat[i][y] == 'X') {
						found = true;
						std::cout << x - i << '\n';
					}
				}
			}
			else if (dir == "ABAJO") {
				for (int i = x + 1; i < F && !found; ++i) {
					if (mat[i][y] == 'X') {
						found = true;
						std::cout << i-x << '\n';
					}
				}
			}
			else if (dir == "DERECHA") {
				for (int j = y + 1; j < C && !found; ++j) {
					if (mat[x][j] == 'X') {
						found = true;
						std::cout << j - y << '\n';
					}
				}
			}
			else {
				for (int j = y - 1; j >= 0 && !found; --j) {
					if (mat[x][j] == 'X') {
						found = true;
						std::cout << y - j << '\n';
					}
				}
			}

			if (!found) std::cout << "NINGUNO\n";
		}

		std::cout << "---\n";
	std::cin >> F >> C;
	}
return 0;
}