#include <iostream>
#include <vector>
#include <string>
#include <stack>

int C, F;

struct coord {
	int x, y;
};

bool simetria1(std::vector<std::string> const& mat) {
	int fin = C / 2;
	bool ok = true;
	for (int i = 0; i < F && ok; ++i) {
		for (int j1 = 0, j2 = C - 1; j1 < fin && ok; ++j1, --j2) {
			ok = mat[i][j1] == mat[i][j2];
		}
	}

	return ok;
}

bool simetria2(std::vector<std::string> const& mat) {
	int fin1 = F / 2, fin2 = (C + 1) / 2;
	bool ok = true;
	for (int i1 = 0, i2 = F - 1; i1 < fin1 && ok; ++i1, --i2) {
		for (int j = 0; j < fin2 && ok; ++j) {
			ok = mat[i1][j] == mat[i2][j];
		}
	}

	return ok;
}

bool unaPieza(std::vector<std::string>& mat) {
	bool found = false;
	coord act;
	for (int i = 0; i < F && !found; ++i) {
		for (int j = 0; j < C && !found; ++j) {
			if (mat[i][j] == 'X') {
				found = true;
				act = { i,j };
			}
		}
	}

	if (!found) return false;
	else {
		mat[act.x][act.y] = 'P';
		std::stack<coord> pila;
		pila.push(act);
		while (!pila.empty()) {
			act = pila.top();
			pila.pop();

			if (act.x > 0 && mat[act.x - 1][act.y] == 'X') {
				mat[act.x - 1][act.y] = 'P';
				pila.push({ act.x - 1,act.y });
			}
			if (act.y > 0 && mat[act.x][act.y - 1] == 'X') {
				mat[act.x][act.y - 1] = 'P';
				pila.push({ act.x,act.y - 1 });
			}
			if (act.y < C - 1 && mat[act.x][act.y + 1] == 'X') {
				mat[act.x][act.y + 1] = 'P';
				pila.push({ act.x,act.y + 1 });
			}
			if (act.x < F - 1 && mat[act.x + 1][act.y] == 'X') {
				mat[act.x + 1][act.y] = 'P';
				pila.push({ act.x + 1,act.y });
			}
		}

		bool ok = true;
		for (int i = 0; i < F && ok; ++i) {
			for (int j = 0; j < C && ok; ++j) {
				ok = mat[i][j] != 'X';
			}
		}
		return ok;
	}
}

bool cortesValidos(std::vector<std::string>& mat) {
	int finF = (F + 1) / 2, finC = (C + 1) / 2;
	coord act;
	//borde superior
	for (int j = 0; j < finC; ++j) {
		if (mat[0][j] == '.') {
			mat[0][j] = 'N';
			std::stack<coord> pila;
			pila.push({ 0,j });
			while (!pila.empty()) {
				act = pila.top();
				pila.pop();

				if (act.x > 0 && mat[act.x - 1][act.y] == '.') {
					mat[act.x - 1][act.y] = 'N';
					pila.push({ act.x - 1,act.y });
				}
				if (act.y > 0 && mat[act.x][act.y - 1] == '.') {
					mat[act.x][act.y - 1] = 'N';
					pila.push({ act.x,act.y - 1 });
				}
				if (act.y < C - 1 && mat[act.x][act.y + 1] == '.') {
					mat[act.x][act.y + 1] = 'N';
					pila.push({ act.x,act.y + 1 });
				}
				if (act.x < F - 1 && mat[act.x + 1][act.y] == '.') {
					mat[act.x + 1][act.y] = 'N';
					pila.push({ act.x + 1,act.y });
				}
			}
		}
	}
	//borde izquierdo
	for (int i = 0; i < finF; ++i) {
		if (mat[i][0] == '.') {
			mat[i][0] = 'N';
			std::stack<coord> pila;
			pila.push({ i,0 });
			while (!pila.empty()) {
				act = pila.top();
				pila.pop();

				if (act.x > 0 && mat[act.x - 1][act.y] == '.') {
					mat[act.x - 1][act.y] = 'N';
					pila.push({ act.x - 1,act.y });
				}
				if (act.y > 0 && mat[act.x][act.y - 1] == '.') {
					mat[act.x][act.y - 1] = 'N';
					pila.push({ act.x,act.y - 1 });
				}
				if (act.y < C - 1 && mat[act.x][act.y + 1] == '.') {
					mat[act.x][act.y + 1] = 'N';
					pila.push({ act.x,act.y + 1 });
				}
				if (act.x < F - 1 && mat[act.x + 1][act.y] == '.') {
					mat[act.x + 1][act.y] = 'N';
					pila.push({ act.x + 1,act.y });
				}
			}
		}
	}
	//borde inferior
	for (int i = finF - 1, j = 0; j < finC; ++j) {
		if (mat[i][j] == '.') {
			mat[i][j] = 'N';
			std::stack<coord> pila;
			pila.push({ i,j });
			while (!pila.empty()) {
				act = pila.top();
				pila.pop();

				if (act.x > 0 && mat[act.x - 1][act.y] == '.') {
					mat[act.x - 1][act.y] = 'N';
					pila.push({ act.x - 1,act.y });
				}
				if (act.y > 0 && mat[act.x][act.y - 1] == '.') {
					mat[act.x][act.y - 1] = 'N';
					pila.push({ act.x,act.y - 1 });
				}
				if (act.y < C - 1 && mat[act.x][act.y + 1] == '.') {
					mat[act.x][act.y + 1] = 'N';
					pila.push({ act.x,act.y + 1 });
				}
				if (act.x < F - 1 && mat[act.x + 1][act.y] == '.') {
					mat[act.x + 1][act.y] = 'N';
					pila.push({ act.x + 1,act.y });
				}
			}
		}
	}
	//borde derecho
	for (int i = 0, j = finC - 1; i < finF; ++i) {
		if (mat[i][j] == '.') {
			mat[i][j] = 'N';
			std::stack<coord> pila;
			pila.push({ i,j });
			while (!pila.empty()) {
				act = pila.top();
				pila.pop();

				if (act.x > 0 && mat[act.x - 1][act.y] == '.') {
					mat[act.x - 1][act.y] = 'N';
					pila.push({ act.x - 1,act.y });
				}
				if (act.y > 0 && mat[act.x][act.y - 1] == '.') {
					mat[act.x][act.y - 1] = 'N';
					pila.push({ act.x,act.y - 1 });
				}
				if (act.y < C - 1 && mat[act.x][act.y + 1] == '.') {
					mat[act.x][act.y + 1] = 'N';
					pila.push({ act.x,act.y + 1 });
				}
				if (act.x < F - 1 && mat[act.x + 1][act.y] == '.') {
					mat[act.x + 1][act.y] = 'N';
					pila.push({ act.x + 1,act.y });
				}
			}
		}
	}

	bool ok = true;
	for (int i = 0; i < finF && ok; ++i) {
		for (int j = 0; j < finC && ok; ++j) {
			ok = mat[i][j] != '.';
		}
	}

	return ok;
}

int main() {
	std::cin >> C >> F;
	while (std::cin) {
		std::vector<std::string> mat(F);
		for (int i = 0; i < F; ++i) std::cin >> mat[i];

		if (simetria1(mat) && simetria2(mat) && unaPieza(mat) && cortesValidos(mat)) std::cout << "CORRECTO\n";
		else std::cout << "TRAMPOSO\n";

		std::cin >> C >> F;
	}
	return 0;
}