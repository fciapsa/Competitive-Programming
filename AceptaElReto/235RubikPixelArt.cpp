#include <iostream>
#include <vector>
#include <string>

int main() {
	int f, c, n;
	std::vector<std::string> cubo(3);
	bool found;
	std::cin >> f >> c;
	while (f != 0) {
		f *= 3;
		c *= 3;
		std::vector<std::string>  m(f);
		std::cin.ignore();
		for (int i = 0; i < f; ++i) getline(std::cin, m[i]);

		std::cin >> n;
		std::cin.ignore();
		for (int k = 0; k < n; ++k) {
			getline(std::cin, cubo[0]);
			getline(std::cin, cubo[1]);
			getline(std::cin, cubo[2]);
			found = false;
			for (int i = 0; i < f && !found; i += 3) {
				for (int j = 0; j < c && !found; j += 3) {
					if (m[i][j] == cubo[0][0] && m[i][j + 1] == cubo[0][1] && m[i][j + 2] == cubo[0][2] &&
						m[i + 1][j] == cubo[1][0] && m[i + 1][j + 1] == cubo[1][1] && m[i + 1][j + 2] == cubo[1][2] &&
						m[i + 2][j] == cubo[2][0] && m[i + 2][j + 1] == cubo[2][1] && m[i + 2][j + 2] == cubo[2][2]) {
						found = true;
						std::cout << i / 3 + 1 << ' ' << j / 3 + 1 << '\n';
					}
				}
			}

			if (!found) std::cout << "NO SE USA\n";
		}

	std::cin >> f >> c;
	}
return 0;
}