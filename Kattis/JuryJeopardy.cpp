#include <bits/stdc++.h>

using namespace std;
#define ll long long

//0-east, 1-west, 2-north, 3-south
vector<int> vx = { 0, 0, -1, 1 };
vector<int> vy = { 1, -1, 0, 0 };

int main() {
	std::ios::sync_with_stdio(false);

	int tc, x, y, maxy, minx, maxx, dir;
	string s;
	cin >> tc;
	cout << tc << '\n';
	while (tc--) {
		cin >> s;
		vector<vector<char>> mat(205, vector<char>(205, '#'));
		x = 102, y = 0;
		mat[x][y] = '.';
		minx = maxx = 102;
		maxy = 0;
		dir = 0;
		for (int i = 0; i < s.size(); ++i) {
			if(s[i] == 'R'){
				if (dir == 0) dir = 3;
				else if (dir == 1) dir = 2;
				else if (dir == 2) dir = 0;
				else dir = 1;
			}
			else if (s[i] == 'L') {
				if (dir == 0) dir = 2;
				else if (dir == 1) dir = 3;
				else if (dir == 2) dir = 1;
				else dir = 0;
			}
			else if (s[i] == 'B') {
				if (dir == 0) dir = 1;
				else if (dir == 1) dir = 0;
				else if (dir == 2) dir = 3;
				else dir = 2;
			}

			x += vx[dir];
			y += vy[dir];
			mat[x][y] = '.';

			minx = min(minx, x);
			maxx = max(maxx, x);
			maxy = max(maxy, y);
		}

		cout << maxx - minx + 3 << ' ' << maxy + 2 << '\n';
		for (int i = minx - 1; i <= maxx + 1; ++i) {
			for (int j = 0; j <= maxy+1; ++j) cout << mat[i][j];
			cout << '\n';
		}
	}

	return 0;
}