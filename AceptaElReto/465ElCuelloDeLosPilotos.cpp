#include <iostream>
#include <vector>
#include <string>

int main() {
	int C, F, x, y, dir, left, right;
	bool found;
	std::cin >> C >> F;
	while (std::cin) {
		std::vector<std::string> mat(F);
		for (int i = 0; i < F; ++i) std::cin >> mat[i];

		found = false;
		for (int i = 0; i < F && !found; ++i) {
			for (int j = 0; j < C && !found; ++j) {
				if (mat[i][j] == 'O') {
					found = true;
					x = i;
					y = j;
				}
			}
		}

		left = 0;
		right = 0;
		found = false;
		if (x > 0 && mat[x - 1][y] == '#') {
			x = x - 1;
			dir = 0;
		}
		else if (y < C - 1 && mat[x][y + 1] == '#') {
			y = y + 1;
			dir = 1;
		}
		else if (x < F - 1 && mat[x + 1][y] == '#') {
			x = x + 1;
			dir = 2;
		}
		else if (y > 0 && mat[x][y - 1] == '#') {
			y = y - 1;
			dir = 3;
		}
		else found = true;

		while (!found) {
			mat[x][y] = '.';

			if (x > 0 && mat[x - 1][y] == '#') {
				if (dir == 1) ++left;
				else if (dir == 3) ++right;
				dir = 0;
				x = x - 1;
			}
			else if (y < C - 1 && mat[x][y + 1] == '#') {
				if (dir == 2) ++left;
				else if (dir == 0) ++right;
				dir = 1;
				y = y + 1;
			}
			else if (x < F - 1 && mat[x + 1][y] == '#') {
				if (dir == 1) ++right;
				else if (dir == 3) ++left;
				dir = 2;
				x = x + 1;
			}
			else if (y > 0 && mat[x][y - 1] == '#') {
				if (dir == 0) ++left;
				else if (dir == 2) ++right;
				dir = 3;
				y = y - 1;
			}
			else found = true;
		}

		if (x > 0 && mat[x - 1][y] == 'O') {
			if (dir == 1) ++left;
			else if (dir == 3) ++right;
		}
		else if (y < C - 1 && mat[x][y + 1] == 'O') {
			if (dir == 2) ++left;
			else if (dir == 0) ++right;
		}
		else if (x < F - 1 && mat[x + 1][y] == 'O') {
			if (dir == 1) ++right;
			else if (dir == 3) ++left;
		}
		else {
			if (dir == 0) ++left;
			else if (dir == 2) ++right;
		}

		if (right > left) std::cout << left << ' ' << right << '\n';
		else std::cout << right << ' ' << left << '\n';

	std::cin >> C >> F;
	}
return 0;
}