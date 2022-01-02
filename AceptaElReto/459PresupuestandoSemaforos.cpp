#include <iostream>
#include <vector>

const int MIN = 2;

int main() {
	int F, C, aux, Fm, Cm, sol;
	std::cin >> C >> F;
	while (std::cin) {
		sol = 0;
		std::vector<std::vector<char>> mat(F, std::vector<char>(C));

		for (int i = 0; i < F; ++i) {
			for (int j = 0; j < C; ++j) std::cin >> mat[i][j];
		}

		Fm = F - 1;
		Cm = C - 1;
		for (int j = 1; j < Cm; ++j) {
			if (mat[0][j] == '#') {
				aux = 0;
				if (mat[0][j - 1] == '#') ++aux;
				if (mat[0][j + 1] == '#') ++aux;
				if (F > 1 && mat[1][j] == '#') ++aux;

				if (aux > MIN) sol += aux;
			}
		}

		for (int i = 1; i < Fm; ++i) {
			for (int j = 0; j < C; ++j) {
				if (mat[i][j] == '#') {
					aux = 0;
					if (mat[i - 1][j] == '#') ++aux;
					if (j > 0 && mat[i][j - 1] == '#') ++aux;
					if (j < Cm && mat[i][j + 1] == '#') ++aux;
					if (i < Fm && mat[i+1][j] == '#') ++aux;

					if (aux > MIN) sol += aux;
				}
			}
		}

		for (int j = 1; j < Cm; ++j) {
			if (mat[Fm][j] == '#') {
				aux = 0;
				if (mat[Fm][j - 1] == '#') ++aux;
				if (mat[Fm][j + 1] == '#') ++aux;
				if (F > 1 && mat[Fm-1][j] == '#') ++aux;

				if (aux > MIN) sol += aux;
			}
		}

		std::cout << sol << '\n';

	std::cin >> C >> F;
	}
return 0;
}