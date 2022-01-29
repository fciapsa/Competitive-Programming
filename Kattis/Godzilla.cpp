#include <bits/stdc++.h>

using namespace std;
#define ll long long

const vector<int> vx = { -1,0,1,0 }, vy = { 0,1,0,-1 };
int c, f;

struct pos {
	int x, y, t;
};

bool inside(int x, int y) {
	return x >= 0 && x < f && y >= 0 && y < c;
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc, ans, dx, dy, time;
	bool moved;
	pos gz, act;
	cin >> tc;
	while (tc--) {
		cin >> c >> f;
		vector<vector<char>> mat(f, vector<char>(c));
		vector<vector<bool>> h_death(f, vector<bool>(c, false));//horizontal shots
		vector<vector<bool>> v_death(f, vector<bool>(c, false));//vertical shots
		vector<vector<bool>> marked1(f, vector<bool>(c, false));//godzilla was here
		vector<vector<bool>> marked2(f, vector<bool>(c, false));//a mech was here
		queue<pos> mechs;
		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> mat[i][j];
				if (mat[i][j] == 'M') {
					mechs.push({ i,j,0 });
					marked2[i][j] = true;
				}
				else if (mat[i][j] == 'G') {
					gz = { i,j,0 };
					marked1[i][j] = true;
					mat[i][j] = '.';
				}
			}
		}

		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) {
				if (mat[i][j] == 'M') {
					mat[i][j] = '.';
					for (int k = i; k >= 0 && mat[k][j] != 'R' && !v_death[k][j]; --k) v_death[k][j] = true;
					for (int k = i + 1; k < f && mat[k][j] != 'R' && !v_death[k][j]; ++k) v_death[k][j] = true;
					for (int k = j; k >= 0 && mat[i][k] != 'R' && !h_death[i][k]; --k) h_death[i][k] = true;
					for (int k = j + 1; k < c && mat[i][k] != 'R' && !h_death[i][k]; ++k) h_death[i][k] = true;
				}
			}
		}

		ans = 0;
		time = 0;
		while (true) {
			moved = false;
			for (int i = 0; i < 4; ++i) {
				dx = gz.x + vx[i];
				dy = gz.y + vy[i];
				if (inside(dx, dy) && mat[dx][dy] == 'R') {
					moved = true;
					++ans;
					marked1[dx][dy] = true;
					mat[dx][dy] = '.';
					if (dx > 0 && v_death[dx - 1][dy]) v_death[dx][dy] = true;
					if (dx < f - 1 && v_death[dx + 1][dy]) v_death[dx][dy] = true;
					if (dy > 0 && h_death[dx][dy - 1]) h_death[dx][dy] = true;
					if (dy < c - 1 && h_death[dx][dy + 1]) h_death[dx][dy] = true;
					if (dx > 0 && dx < f-1 && v_death[dx + 1][dy]) {
						for (int k = dx-1; k >= 0 && !v_death[k][dy] && mat[k][dy] != 'R'; --k) v_death[k][dy] = true;
					}
					if (dx < f-1 && dx > 0 && v_death[dx - 1][dy]) {
						for (int k = dx+1; k < f && !v_death[k][dy] && mat[k][dy] != 'R'; ++k) v_death[k][dy] = true;
					}
					if (dy > 0 && dy < c - 1 && h_death[dx][dy+1]) {
						for (int k = dy - 1; k >= 0 && !h_death[dx][k] && mat[dx][k] != 'R'; --k) h_death[dx][k] = true;
					}
					if (dy < c - 1 && dy > 0 && h_death[dx][dy-1]) {
						for (int k = dy + 1; k < c && !h_death[dx][k] && mat[dx][k] != 'R'; ++k) h_death[dx][k] = true;
					}
					gz.x = dx;
					gz.y = dy;
					break;
				}
			}
			if (!moved) {
				for (int i = 0; i < 4; ++i) {
					dx = gz.x + vx[i];
					dy = gz.y + vy[i];
					if (inside(dx, dy) && !marked1[dx][dy]) {
						marked1[dx][dy] = true;
						gz.x = dx;
						gz.y = dy;
						break;
					}
				}
			}

			if(v_death[gz.x][gz.y] || h_death[gz.x][gz.y]) break;
			//mechs turn
			while (!mechs.empty() && mechs.front().t == time) {
				act = mechs.front();
				mechs.pop();

				for (int i = 0; i < 4; ++i) {
					dx = act.x + vx[i];
					dy = act.y + vy[i];
					if (inside(dx, dy) && mat[dx][dy] != 'R' && !marked2[dx][dy]) {
						marked2[dx][dy] = true;
						mechs.push({ dx,dy,act.t + 1 });
						v_death[dx][dy] = true;
						h_death[dx][dy] = true;
						for (int k = dx-1; k >= 0 && mat[k][dy] != 'R' && !v_death[k][dy]; --k) v_death[k][dy] = true;
						for (int k = dx + 1; k < f && mat[k][dy] != 'R' && !v_death[k][dy]; ++k) v_death[k][dy] = true;
						for (int k = dy-1; k >= 0 && mat[dx][k] != 'R' && !h_death[dx][k]; --k) h_death[dx][k] = true;
						for (int k = dy + 1; k < c && mat[dx][k] != 'R' && !h_death[dx][k]; ++k) h_death[dx][k] = true;
					}
				}
			}

			++time;
			if (v_death[gz.x][gz.y] || h_death[gz.x][gz.y]) break;
		}
		cout << ans << '\n';
	}
	return 0;
}