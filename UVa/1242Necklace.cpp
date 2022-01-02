#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define INF 1e9

int n;

vector<bool> visited;
vector<int> parent;
vector<unordered_set<int>> adj;
vector<vector<int>> cap;

void bfs(int s, int t) {
	queue<int> q;
	visited.assign(n, false);
	q.push(s);
	parent[s] = -1; visited[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int v: adj[u]) {
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
	int iter = 0;//solo 2 veces
	do {
		flow = sendFlow(s, t);
		ret += flow;
	} while (flow > 0 && ++iter < 2);
	return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
	int m, s, t, k = 1, a, b;
    cin >> n >> m;
    while (n != 0) {
		n += 2;
		adj.assign(n, {});
		parent.assign(n, 0);
		cap.assign(n, vector<int>(n));
		for(int i = 0; i < m; ++i){
			cin >> a >> b;
			adj[a].insert(b);
			adj[b].insert(a);
			cap[a][b] += 1;
			cap[b][a] += 1;
		}
		cin >> s >> t;
		adj[0].insert(s);
		adj[s].insert(0);
		cap[0][s] = 2;
		cap[s][0] = 2;
		adj[t].insert(n - 1);
		adj[n - 1].insert(t);
		cap[t][n - 1] = 2;
		cap[n - 1][t] = 2;

		cout << "Case " << k++ << ": ";
		if (s == t || edmondsKarp(s, t) >= 2) cout << "YES\n";
		else cout << "NO\n";
    cin >> n >> m;
    }
    return 0;
}