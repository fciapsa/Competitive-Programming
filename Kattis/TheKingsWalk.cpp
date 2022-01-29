#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MOD 5318008

vector<int> to;

void ccw90(int &x, int &y) {
	int aux = x;
	x = y;
	y = to[aux];
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, x1, y1, x2, y2, p1, p2;
	cin >> tc;
	while (tc--) {
		cin >> n >> x1 >> y1 >> x2 >> y2;
		to.assign(n + 1, 0);
		for (int i = 1, j = n; i <= n; ++i, --j) {
			to[i] = j;
		}

		//reduce to case x1 < x2 AND |y1-y2| <= x2-x1
		while (x1 >= x2 || abs(y1 - y2) > x2 - x1) {
			ccw90(x1, y1);
			ccw90(x2, y2);
		}

		vector<int> miny(n + 1);
		vector<int> maxy(n + 1);
		for (int i = x1, t1 = y1, t2 = y1; i <= x2; ++i, --t1, ++t2) {
			miny[i] = max(t1,1);
			maxy[i] = min(t2,n);
		}
		for (int i = x2, t1 = y2, t2 = y2; i >= x1; --i, --t1, ++t2) {
			miny[i] = max(miny[i], t1);
			maxy[i] = min(maxy[i], t2);
		}

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		dp[x1][y1] = 1;
		for (int row = x1 + 1; row <= x2; ++row) {
			for (int col = miny[row]; col <= maxy[row]; ++col) {
				if (col - 1 >= miny[row - 1] && col-1 <= maxy[row-1])
					dp[row][col] = dp[row - 1][col - 1];
				if (col >= miny[row - 1] && col <= maxy[row - 1])
					dp[row][col] = (dp[row][col] + dp[row - 1][col]) % MOD;
				if (col+1 >= miny[row - 1] && col+1 <= maxy[row - 1])
					dp[row][col] = (dp[row][col] + dp[row - 1][col+1]) % MOD;
			}
		}

		cout << dp[x2][y2] << '\n';
	}
	return 0;
}