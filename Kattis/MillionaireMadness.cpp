#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> vx = { -1,0,1,0 }, vy = { 0,1,0,-1 };

struct edge {
	int to, cost;
	bool operator<(edge const& o)const {
		return cost > o.cost;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	int m, n, x, y;
	cin >> m >> n;
	vector<vector<int>> mat(m, vector<int>(n));
	vector<vector<edge>> adyList(m * n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) cin >> mat[i][j];

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int d = 0; d < 4; ++d) {
				x = i + vx[d];
				y = j + vy[d];
				if (x >= 0 && x < m && y >= 0 && y < n) {
					adyList[i * n + j].push_back({ x * n + y, max(0 , mat[x][y] - mat[i][j]) });
				}
			}
		}
	}

	vector<int> max_to(m * n, 1e9);
	max_to[0] = 0;
	priority_queue<edge> pq;
	pq.push({ 0, 0 });
	edge act;
	while (!pq.empty()) {
		act = pq.top();
		pq.pop();

		if (act.cost > max_to[act.to]) continue;

		for (edge e : adyList[act.to]) {
			if (max_to[e.to] > max(act.cost, e.cost)) {
				max_to[e.to] = max(act.cost, e.cost);
				pq.push({ e.to, max_to[e.to] });
			}
		}
	}

	cout << max_to[m * n - 1] << '\n';

	return 0;
}