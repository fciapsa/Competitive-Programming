//Flavius Abel Ciapsa

#include <iostream>
#include <vector>
#include <string>
#include <cctype>//isdigit
#include <climits>//INT_MAX
#include <queue>

struct tCasilla {
	int x, y;
};

bool BFS(std::vector<std::string>  const& mat, tCasilla in, tCasilla out, std::vector<std::vector<bool>>& marked, 
	std::vector<std::vector<int>>& distTo, int F, int C) {

	std::queue<tCasilla> cola;

	marked[in.x][in.y] = true;
	distTo[in.x][in.y] = 0;

	tCasilla act, ady;
	cola.push(in);
	while (!cola.empty()) {
		act = cola.front();
		cola.pop();

		ady = { act.x + 1, act.y };//abajo
		if (ady.x < F && mat[ady.x][ady.y] != '#' && mat[ady.x][ady.y] != 'x' && !marked[ady.x][ady.y]) {
			marked[ady.x][ady.y] = true;
			distTo[ady.x][ady.y] = distTo[act.x][act.y] + 1;
			cola.push(ady);

			if (ady.x == out.x && ady.y == out.y) return true;
		}
		ady = { act.x - 1,act.y };//arriba
		if (ady.x > -1 && mat[ady.x][ady.y] != '#' && mat[ady.x][ady.y] != 'x' && !marked[ady.x][ady.y]) {
			marked[ady.x][ady.y] = true;
			distTo[ady.x][ady.y] = distTo[act.x][act.y] + 1;
			cola.push(ady);

			if (ady.x == out.x && ady.y == out.y) return true;
		}
		ady = { act.x,act.y + 1 };//derecha
		if (ady.y < C && mat[ady.x][ady.y] != '#' && mat[ady.x][ady.y] != 'x' && !marked[ady.x][ady.y]) {
			marked[ady.x][ady.y] = true;
			distTo[ady.x][ady.y] = distTo[act.x][act.y] + 1;
			cola.push(ady);

			if (ady.x == out.x && ady.y == out.y) return true;
		}
		ady = { act.x,act.y - 1 };//izquierda
		if (ady.y > -1 && mat[ady.x][ady.y] != '#' && mat[ady.x][ady.y] != 'x' && !marked[ady.x][ady.y]) {
			marked[ady.x][ady.y] = true;
			distTo[ady.x][ady.y] = distTo[act.x][act.y] + 1;
			cola.push(ady);

			if (ady.x == out.x && ady.y == out.y) return true;
		}
	}

return false;
}

void resuelveCaso() {
	int C, F;
	std::cin >> C >> F;

	std::cin.ignore();//ignorar el salto de linea tras F
	std::vector<std::string> mat(F);
	for (int i = 0; i < F; ++i) {
		getline(std::cin, mat[i]);
	}

	tCasilla in = { -1,-1 }, out = { -1,-1 };
	//Transformo lo cubierto por sensores en un nuevo tipo de casilla intraspasable x
	for (int i = 0; i < F; ++i) {
		for (int j = 0; j < C; ++j) {
			if (isdigit(mat[i][j])) {
				int k = mat[i][j] - '0';

				mat[i][j] = 'x';
				for (int m = i + 1; m <= i + k && m < F && mat[m][j] != '#'; ++m) {
					if(!isdigit(mat[m][j])) mat[m][j] = 'x';//abajo
				}
				for (int m = i - 1; m >= i - k && m > -1 && mat[m][j] != '#'; --m) {
					if (!isdigit(mat[m][j])) mat[m][j] = 'x';//arriba
				}
				for (int n = j + 1; n <= j + k && n < C && mat[i][n] != '#'; ++n) {
					if (!isdigit(mat[i][n])) mat[i][n] = 'x';//derecha
				}
				for (int n = j - 1; n >= j - k && n > -1 && mat[i][n] != '#'; --n) {
					if (!isdigit(mat[i][n])) mat[i][n] = 'x';//izquierda
				}

			}
			else if (mat[i][j] == 'E') in = { i,j };
			else if (mat[i][j] == 'P') out = { i,j };
		}
	}

	if (in.x == -1 || out.x == -1) std::cout << "NO\n";
	else if (mat[in.x][in.y] == 'x' || mat[out.x][out.y] == 'x') std::cout << "NO\n";
	else {
		std::vector<std::vector<int>> distTo(F, std::vector<int>(C,INT_MAX));
		std::vector<std::vector<bool>> marked(F,std::vector<bool> (C,false));
		if (BFS(mat, in, out, marked, distTo,F,C)) std::cout << distTo[out.x][out.y] << '\n';
		else std::cout << "NO\n";
	}
}

int main() {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) resuelveCaso();
return 0;
}