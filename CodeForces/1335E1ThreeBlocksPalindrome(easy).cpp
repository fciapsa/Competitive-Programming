#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T, n, ans, mostx, mosty, aux;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		ans = 0;
		cin >> n;
		vector<int> v(n);
		vector<vector<int>> reps(27, vector<int>(n));
		map<int, int> map;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			++map[v[i]];
			for (int k = 1; k < 27; ++k) reps[k][i] = map[k];
			if (map[v[i]] > ans) ans = map[v[i]];
		}

		//vector<vector<int>> dp(n, vector<int>(n));
		//for (int i = 0; i < n; ++i) dp[i][i] = 1;

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				mostx = 0;
				mosty = 0;
				for (int k = 1; k < 27; ++k) {
					aux = std::min(reps[k][i], (reps[k][n - 1] - reps[k][j - 1]));
					if (aux > mostx) mostx = aux;
					aux = reps[k][j - 1] - reps[k][i];
					if (aux > mosty) mosty = aux;
				}
				
				aux = 2 * mostx + mosty;
				if (aux > ans) ans = aux;
			}
		}

		cout << ans << '\n';
	}

return 0;
}