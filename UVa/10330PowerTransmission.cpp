#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define INF 1e9

int nv;
vector<bool> visited;
vector<int> parent;
vector<unordered_set<int>> adj;
vector<vector<int>> cap;

void bfs(int s, int t) {
	queue<int> q;
	visited.assign(nv, false);
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
		// Buscamos capacidad m´as peque˜na en el camino
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
	int n, m, capa, a, b, B, D;
	cin >> n;
	while (cin) {
		nv = 2 * n + 2;//los n desdoblados, barisal = 0 y dhaka = 2*n+ 1
		cap.assign(nv, vector<int>(nv));
		parent.assign(nv, 0);
		adj.assign(nv, {});
		for (int i = 1, id = 1; i <= n; ++i, id += 2) {
			cin >> capa;
			adj[id].insert(id + 1);
			adj[id + 1].insert(id);
			cap[id][id + 1] = capa;
		}

		cin >> m;
		while (m--) {
			cin >> a >> b >> capa;
			adj[2*a].insert(2*b-1);
			adj[2*b-1].insert(2*a);
			cap[2*a][2*b-1] += capa;
		}

		cin >> B >> D;
		while (B--) {
			cin >> b;
			cap[0][2*b-1] = INF;
			adj[0].insert(2*b-1);
			adj[2*b-1].insert(0);
		}
		while (D--) {
			cin >> a;
			cap[2*a][nv - 1] = INF;
			adj[2*a].insert(nv - 1);
			adj[nv - 1].insert(2*a);
		}

		cout << edmondsKarp(0,nv-1) << '\n';

    cin >> n;
	}

    return 0;
}