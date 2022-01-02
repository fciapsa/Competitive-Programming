#include <iostream>
#include <vector>

struct tPollito {
	int x, y, fuerza;
	char dir;
};

int main() {
	int T, f, c, n, x, y, fuerza, keep_dir, turns;
	bool ok;
	char dir;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> f >> c >> n;

		std::vector<tPollito> v(n);
		for (int j = 0; j < n; ++j) {
			std::cin >> v[j].x >> v[j].y >> v[j].dir >> v[j].fuerza;
			--v[j].x;
			--v[j].y;
		}

		std::vector<std::vector<int>> sol(f, std::vector<int>(c));
		for (int j = 0; j < n; ++j) {
			turns = 0;
			x = v[j].x;
			y = v[j].y;
			dir = v[j].dir;
			fuerza = v[j].fuerza;
			keep_dir = 1;
			ok = true;
			++sol[x][y];
			while (fuerza != 0 && ok) {
				if (keep_dir == 0) {
					++turns;
					switch (dir) {
					    case 'N': dir = 'E'; break;
						case 'E': dir = 'S'; break;
						case 'S': dir = 'W'; break;
						case 'W': dir = 'N'; break;
					}
					keep_dir = turns / 2 + 1;
				}

				switch (dir) {
				case 'N': 
					if (x - 1 >= 0) {
						--x;
						++sol[x][y];
					}
					else ok = false; break;
				case 'E':
					if (y + 1 < c) {
						++y;
						++sol[x][y];
					}
					else ok = false; break;
				case 'S':
					if (x + 1 < f) {
						++x;
						++sol[x][y];
					}
					else ok = false;  break;
				case 'W': 
					if (y - 1 >= 0) {
						--y;
						++sol[x][y];
					}
					else ok = false; break;
				}
				--keep_dir;
				--fuerza;
			}
		}


		for (int j = 0; j < f; ++j) {
			std::cout << sol[j][0];
			for (int k = 1; k < c; ++k) {
				std::cout << ' ' << sol[j][k];
			}
			std::cout << '\n';
		}
		std::cout << "---\n";
	}
return 0;
}

