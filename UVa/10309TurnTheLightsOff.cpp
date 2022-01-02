#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<string> mat(10), matc;
int mn, cont, aux;

void cambio(int x, int y, vector<string> &m) {
	if (m[x][y] == 'O') m[x][y] = '#';
	else m[x][y] = 'O';

	if (x > 0) {
		if (m[x-1][y] == 'O') m[x-1][y] = '#';
		else m[x-1][y] = 'O';
	}
	if (x < 9) {
		if (m[x + 1][y] == 'O') m[x + 1][y] = '#';
		else m[x + 1][y] = 'O';
	}
	if (y > 0) {
		if (m[x][y-1] == 'O') m[x][y-1] = '#';
		else m[x][y-1] = 'O';
	}
	if (y < 9) {
		if (m[x][y+1] == 'O') m[x][y+1] = '#';
		else m[x][y+1] = 'O';
	}
}

void backtrack(int p) {
	if (p == 10) {
		matc = mat;
		aux = 0;
		for (int i = 1; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (matc[i - 1][j] == '#') continue;
				cambio(i, j, matc);
				++aux;
			}
		}

		bool off = true;
		for (int j = 0; j < 10 && off; ++j) {
			off = matc[9][j] == '#';
		}

		if (off) mn = min(mn, cont + aux);
	}
	else {
		backtrack(p + 1);

		cambio(0, p, mat);
		++cont;
		backtrack(p + 1);
		--cont;
		cambio(0, p, mat);
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	string nomb;
	cin >> nomb;
	while (nomb != "end") {
		for (int i = 0; i < 10; ++i) cin >> mat[i];

		mn = 101;
		cont = 0;
		backtrack(0);

		if (mn > 100) mn = -1;
		cout << nomb << ' ' << mn << '\n';
	cin >> nomb;
	}

	return 0;
}