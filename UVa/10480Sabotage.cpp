#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
vector<bool> visited;
vector<int> parent;
vector<vector<ll>> adj, cap;

void bfs(int s, int t) {
	queue<int> q;
	visited.assign(n+1,false);
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

ll sendFlow(int s, int t) {
	// Intentamos llegar de s a t
	bfs(s, t);
	if (!visited[t])
		return 0; // No pudimos
		// Buscamos capacidad m´as peque˜na en el camino
	ll flow = 2e12;
	int v = t;
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

ll edmondsKarp(int s, int t) {
	ll ret = 0;
	ll flow = 0;
	do {
		flow = sendFlow(s, t);
		ret += flow;
	} while (flow > 0);
	return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
	int m, a, b, w;
    cin >> n >> m;
    while (n != 0) {
		adj.assign(n + 1, {});
		cap.assign(n + 1, vector<ll>(n + 1));
		while (m--) {
			cin >> a >> b >> w;
			adj[a].push_back(b);
			adj[b].push_back(a);
			cap[a][b] = w;
			cap[b][a] = w;
		}

		parent.assign(n + 1, -1);
		edmondsKarp(1, 2);
		//tras el ultimo BFS, los vertices visitados son los del lado S
		for (int u = 1; u <= n; ++u) {
			for (int v : adj[u]) {
				if (visited[u] && !visited[v]) cout << u << ' ' << v << '\n';
			}
		}
		cout << '\n';

    cin >> n >> m;
    }
    return 0;
}