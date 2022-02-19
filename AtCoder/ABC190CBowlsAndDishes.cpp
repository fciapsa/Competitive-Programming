#include <iostream>
#include <vector>
#include <string>
#include <algorithm>//max

using namespace std;
int n, m, k;

struct par {
	int a, b;
};

int solve(vector<int>& balls, vector<par> const& conds, vector<par> const& opts, int lvl) {
	if (lvl == k) {
		int cont = 0;
		for (int i = 0; i < m; ++i) {
			if (balls[conds[i].a] && balls[conds[i].b]) ++cont;
		}
		return cont;
	}

	++balls[opts[lvl].a];
	int res1 = solve(balls, conds, opts, lvl + 1);
	--balls[opts[lvl].a];
	++balls[opts[lvl].b];
	int res2 = solve(balls, conds, opts, lvl + 1);
	--balls[opts[lvl].b];
	return std::max(res1, res2);
}

int main() {
	cin >> n >> m;
	vector<int> balls(n + 1, 0);
	vector<par> conds(m);
	for (int i = 0; i < m; ++i) cin >> conds[i].a >> conds[i].b;

	cin >> k;
	vector<par> opts(k);
	for (int i = 0; i < k; ++i) cin >> opts[i].a >> opts[i].b;

	cout << solve(balls, conds, opts, 0) << '\n';

return 0;
}