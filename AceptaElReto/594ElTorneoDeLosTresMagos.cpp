#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
using ll = long long int;

vector<int> vx = { -1,0,1,0 };
vector<int> vy = { 0,1,0, -1 };

struct nodo {
	int posx, posy, lvl;
};

int main() {
	int C, F, a, b, solBFS, solMD, x, y, posaux, cont, mirada;
	cin >> C >> F;
	while (cin) {
		vector<string> mat(F);
		for (int i = 0; i < F; ++i) cin >> mat[i];

		a = F - 1;
		b = -1;
		for (int j = 0; b == -1; ++j) {
			if (mat[a][j] == '.') b = j;
		}

		solBFS = INT_MAX;
		vector<bool> marked(F * C, false);
		marked[a * C + b] = true;
		queue<nodo> q;
		q.push({ a,b,0 });
		nodo act;
		while (!q.empty() && solBFS == INT_MAX) {
			act = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				x = act.posx + vx[i];
				y = act.posy + vy[i];
				if (x >= 0 && x < F && y >= 0 && y < C) {
					posaux = x * C + y;
					if (mat[x][y] != '#' && !marked[posaux]) {
						marked[posaux] = true;
						if (mat[x][y] == 'T') solBFS = act.lvl + 1;
						else q.push({ x,y,act.lvl + 1 });
					}
				}
			}
		}

		if (solBFS == INT_MAX) cout << "IMPOSIBLE\n";
		else {
			solMD = INT_MAX;
			cont = 0;
			mirada = 0;//0 arriba, 1 derecha, 2 abajo, 3 izquierda
			x = a;
			y = b;

			if (mat[x - 1][y] == 'T') solMD = 1;
			else if (mat[x - 1][y + 1] == 'T') solMD = 2;
			else {
				if (mat[x - 1][y + 1] == '#') {
					--x;//avanzo
					++cont;
				}
				else {//giro esquina
					--x;
					++y;
					mirada = 1;
					cont += 2;
				}

				while (true) {
					if (x == a) break;//he vuelto al inicio

					if (mirada == 0) {
						if (mat[x - 1][y] == 'T') {
							solMD = cont + 1;
							break;
						}
						else if (mat[x - 1][y] == '.') {
							if (mat[x - 1][y + 1] == '#') {
								--x;
								++cont;
							}
							else if (mat[x - 1][y + 1] == 'T') {
								solMD = cont + 2;
								break;
							}
							else {
								--x;
								++y;
								cont += 2;
								mirada = 1;
							}
						}
						else mirada = 3;
					}
					else if (mirada == 1) {
						if (mat[x][y + 1] == 'T') {
							solMD = cont + 1;
							break;
						}
						else if (mat[x][y + 1] == '.') {
							if (mat[x + 1][y + 1] == '#') {
								++y;
								++cont;
							}
							else if (mat[x + 1][y + 1] == 'T') {
								solMD = cont + 2;
								break;
							}
							else {
								++x;
								++y;
								cont += 2;
								mirada = 2;
							}
						}
						else mirada = 0;
					}
					else if (mirada == 2) {
						if (mat[x + 1][y] == 'T') {
							solMD = cont + 1;
							break;
						}
						else if (mat[x + 1][y] == '.') {
							if (mat[x + 1][y - 1] == '#') {
								++x;
								++cont;
							}
							else if (mat[x + 1][y - 1] == 'T') {
								solMD = cont + 2;
								break;
							}
							else {
								++x;
								--y;
								cont += 2;
								mirada = 3;
							}
						}
						else mirada = 1;
					}
					else {
						if (mat[x][y - 1] == 'T') {
							solMD = cont + 1;
							break;
						}
						else if (mat[x][y - 1] == '.') {
							if (mat[x - 1][y - 1] == '#') {
								--y;
								++cont;
							}
							else if (mat[x - 1][y - 1] == 'T') {
								solMD = cont + 2;
								break;
							}
							else {
								--x;
								--y;
								cont += 2;
								mirada = 0;
							}
						}
						else mirada = 2;
					}
				}
			}

			if (solMD == INT_MAX) cout << "INF\n";
			else if (solBFS == solMD) cout << "IGUAL\n";
			else cout << solMD - solBFS << '\n';
		}

	cin >> C >> F;
	}

return 0;
}