#include <iostream>
#include <vector>

int main() {
	int C, F, j, i, a, sol;
	std::cin >> C >> F >> a;
	while (C != 0) {
		if (a == 0) std::cout << "0\n";
		else {
			sol = 0;
			std::vector<std::vector<char>> mat(F, std::vector<char>(C, ' '));
			for (int k = 0; k < a; ++k) {
				std::cin >> j >> i;
				--i;
				--j;
				if (mat[i][j] == 's') --sol;
				mat[i][j] = 'x';
				
				if (i > 0) {//fila anterior
					if (mat[i - 1][j] == ' ') {//debajo
						++sol;
						mat[i - 1][j] = 's';
					}
					if (j > 0 && mat[i - 1][j - 1] == ' ') {//arriba-izquierda
						++sol;
						mat[i - 1][j - 1] = 's';
					}
					if (j < C - 1 && mat[i - 1][j + 1] == ' ') {//arriba-derecha
						++sol;
						mat[i - 1][j + 1] = 's';
					}
				}

				if (j > 0 && mat[i][j - 1] == ' ') {//izquierda
					++sol;
					mat[i][j - 1] = 's';
				}
				if (j < C - 1 && mat[i][j+1] == ' ') {//derecha
					++sol;
					mat[i][j + 1] = 's';
				}

				if (i < F - 1) {
					if (mat[i +1][j] == ' ') {//encima
						++sol;
						mat[i +1][j] = 's';
					}
					if (j > 0 && mat[i + 1][j - 1] == ' ') {//abajo-izquierda
						++sol;
						mat[i +1][j - 1] = 's';
					}
					if (j < C - 1 && mat[i + 1][j + 1] == ' ') {//abajo-derecha
						++sol;
						mat[i + 1][j + 1] = 's';
					}
				}
			}

			std::cout << sol << '\n';
		}

	std::cin >> C >> F >> a;
	}
return 0;
}