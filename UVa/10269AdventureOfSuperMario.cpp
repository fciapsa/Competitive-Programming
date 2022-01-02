#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define INF 1e9

struct par {
	int v, k, prio;
	bool operator<(par const& other) const {
		return prio > other.prio;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	int tc, a, b, m, l, k, V, x, y, dist;
	cin >> tc;
	while (tc--) {
		cin >> a >> b >> m >> l >> k;
		V = a + b;
		vector<vector<int>> ady(V + 1, vector<int>(V + 1, INF));
		for (int i = 0; i < m; ++i) {
			cin >> x >> y >> dist;
			ady[x][y] = dist;
			ady[y][x] = dist;
		}

		for (int k = 1; k <= a; ++k) {
			for (int i = 1; i <= V; ++i) {
				for (int j = 1; j <= V; ++j) {
					if (ady[i][k] != INF && ady[k][j] != INF && ady[i][k] + ady[k][j] < ady[i][j]) {
						ady[i][j] = ady[i][k] + ady[k][j];
					}
				}
			}
		}

		vector<vector<int>> dist(V + 1, vector<int>(k + 1, INF));
		dist[V][k] = 0;
		priority_queue<par> pq;
		pq.push({ V, k, 0});

		par act;
		while (!pq.empty()) {
			act = pq.top();
			pq.pop();

			if (act.prio > dist[act.v][act.k]) continue;

			for (int w = 1; w <= V; ++w) {
				if (ady[act.v][w] != INF) {
					if (act.k && ady[act.v][w] <= l) {
						if (act.prio < dist[w][act.k - 1]) {
							dist[w][act.k - 1] = act.prio;
							pq.push({ w,act.k-1,act.prio });
						}
					}

					if (act.prio + ady[act.v][w] < dist[w][act.k]) {
						dist[w][act.k] = act.prio + ady[act.v][w];
						pq.push({ w,act.k, dist[w][act.k] });
					}
				}
			}
		}

		int sol = INF;
		for (int i = 0; i <= k; ++i) sol = min(sol, dist[1][i]);
		cout << sol << '\n';
	}
	return 0;
}