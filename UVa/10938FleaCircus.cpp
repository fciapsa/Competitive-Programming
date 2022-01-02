#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define MAX_N 5005

int n, path[MAX_N], pn;
vector<int> adj[MAX_N];

bool dfs(int u, int p, int dest) {
	path[pn++] = u;
	if (u == dest) return true;
	for (int v: adj[u]) {
		if (v == p) continue;
		if (dfs(v, u, dest)) return true;
	}
	pn--;
	return false;
}

int main() {
	int u, v, q, a, b, p1, p2;
	cin >> n;
	while (n != 0) {
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		int u, v;
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int q;
		cin >> q;
		while (q--) {
			cin >> a >> b;
			pn = 0;
			dfs(a, -1, b);
			if (pn % 2) cout << "The fleas meet at " << path[pn / 2] << ".\n";
			else {
				p1 = path[pn / 2 - 1];
				p2 = path[pn / 2];
				if (p1 > p2) swap(p1, p2);
				cout << "The fleas jump forever between " << p1 << " and " << p2 << ".\n";
			}
		}
		cin >> n;
	}
return 0;
}