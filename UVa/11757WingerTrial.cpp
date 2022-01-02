#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct punto {
	int x, y;
};

#define INF 1e9

vector<bool> visited;
vector<int> parent;
vector<vector<int>> adj, cap;

void bfs(int s, int t) {
	queue<int> q;
	visited.assign(adj.size(), false);
	q.push(s);
	parent[s] = -1; visited[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if (!visited[v] && (cap[u][v] > 0)) {
				parent[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}
	}
}
int sendFlow(int s, int t) {
	// Intentamos llegar de s a t
	bfs(s, t);
	if (!visited[t])
		return 0; // No pudimos
		// Buscamos capacidad mas pequena en el camino
	int flow = INF, v = t;
	while (v != s) {
		flow = min(cap[parent[v]][v], flow);
		v = parent[v];
	}
	// Mandamos flujo
	v = t;
	while (v != s) {
		cap[parent[v]][v] -= flow;
		cap[v][parent[v]] += flow; // INVERSA
		v = parent[v];
	}
	return flow;
}
int edmondsKarp(int s, int t) {
	int ret = 0;
	int flow = 0;
	do {
		flow = sendFlow(s, t);
		ret += flow;
	} while (flow > 0);
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	int l, w, n, d, d2, k = 1;
	cin >> l >> w >> n >> d;
	while (l != 0) {
		adj.assign(2*n + 2, {});
		cap.assign(2*n + 2, vector<int>(2*n + 2, 0));
		d2 = 4 * d * d;

		vector<punto> v(n+1);
		for (int i = 1; i <= n; ++i) {
			adj[2 * i - 1].push_back(2 * i);
			adj[2 * i].push_back(2 * i - 1);
			cap[2 * i - 1][2 * i] = 1;

			cin >> v[i].x >> v[i].y;
			if (v[i].y <= d) {
				adj[0].push_back(2*i-1);
				adj[2*i-1].push_back(0);
				cap[0][2*i-1] = INF;
			}
			if (v[i].y >= w - d) {
				adj[2*n + 1].push_back(2*i);
				adj[2*i].push_back(2*n + 1);
				cap[2 * i][2 * n + 1] = INF;
			}

			for (int j = 1; j < i; ++j) {
				if ((v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y) <= d2) {
					adj[2*i].push_back(2*j-1);
					adj[2 * j - 1].push_back(2 * i);
					adj[2*j].push_back(2*i-1);
					adj[2 * i - 1].push_back(2 * j);
					cap[2*i][2*j-1] = INF;
					cap[2*j][2*i-1] = INF;
				}
			}
		}

		parent.assign(2*n + 2, -1);
		cout << "Case " << k++ << ": " << edmondsKarp(0,2*n+1) << '\n';

	cin >> l >> w >> n >> d;
	}
	return 0;
}