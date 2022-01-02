#include <iostream>
#include <vector>
#include <algorithm>//min,max

struct tPos {
	int x, y;
};

bool resuelve() {
	int C, F;
	std::cin >> C >> F;

	if (!std::cin) return false;

	std::vector<std::vector<int>> mat(F, std::vector<int>(C));
	for (int i = 0; i < F; ++i) {
		for (int j = 0; j < C; ++j) std::cin >> mat[i][j];
	}

	std::vector<std::vector<int>> memoria(F, std::vector<int>(C, -1));
	memoria[F - 1][C - 1] = 2;
	/*El camino mas corto vendra dado siempre por moverse solo hacia abajo o hacia la izquierda.
	Planteando el problema del final al inicio, por tanto, necesitaremos los valores de las celdas
	de debajo y de la izquierda para saber el minimo necesario desde esa celda.
	*/
	for (int i = F - 2, j = C - 1; i >= 0; --i) { //relleno la ultima columna
		if (mat[i][j] >= 0) memoria[i][j] = std::max(memoria[i + 1][j] - mat[i][j], 2);
		else memoria[i][j] = memoria[i + 1][j] - mat[i][j];
	}
	for (int i = F-1, j = C-2; j >= 0; --j) { //relleno la ultima fila
		if (mat[i][j] >= 0) memoria[i][j] = std::max(memoria[i][j + 1] - mat[i][j], 2);
		else memoria[i][j] = memoria[i][j + 1] - mat[i][j];
	}
	//relleno el resto de la matriz de abajo hacia arriba y de derecha a izquierda
	int i = F - 2, j;
	while (i >= 0) {
		j = C - 2;
		while (j >= 0) {
			if (mat[i][j] >= 0) {
				memoria[i][j] = std::min(std::max(2, memoria[i][j + 1] - mat[i][j]),
					std::max(2, memoria[i + 1][j] - mat[i][j]));
			}
			else memoria[i][j] = std::min(memoria[i + 1][j] - mat[i][j], memoria[i][j + 1] - mat[i][j]);
		--j;
		}
	--i;
	}

	std::cout << memoria[0][0] << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}