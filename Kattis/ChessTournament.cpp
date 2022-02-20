#include <bits/stdc++.h>

using namespace std;
#define ll long long

/*This problem is equivalent to checking if there is a cycle having at least one directed edge in the graph
built considering ties as undirected edges and wins as directed edges.
*/

struct ufds {
	vector<int> p, r, n;
	int numSets;
	ufds(int N) : p(N, 0), r(N, 0), n(N, 1), numSets(N) {
		iota(p.begin(), p.end(), 0);
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool sameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x == y) return;
		if (r[x] > r[y]) swap(x, y);
		p[x] = y;
		n[y] += n[x];
		r[y] += r[x] == r[y];
		--numSets;
	}
	int sizeSet(int i) { return n[findSet(i)]; }
};

#define NUEVO 0
#define TOCADO 1
#define HUNDIDO 2
vector<int> state;
vector<unordered_set<int>> adyList;

bool hasCycle(int u) {
	state[u] = TOCADO;

	for (int v : adyList[u]) {
		if (state[v] == TOCADO) return true;
		if (state[v] == NUEVO && hasCycle(v)) return true;
	}

	state[u] = HUNDIDO;
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n, m, a, b;
	char c;
	cin >> n >> m;
	ufds uf(n);
	vector<pair<int, int>> directed_edges;
	while (m--) {
		cin >> a >> c >> b;
		if (c == '=') uf.unionSet(a, b);
		else directed_edges.push_back({ a,b });
	}

	bool ok = true;
	//check if there are self-loops between tied players
	for (auto p: directed_edges) {
		if (uf.findSet(p.first) == uf.findSet(p.second)) ok = false;
	}

	if (!ok) cout << "inconsistent\n";
	else {
		adyList.assign(n, {});
		for (auto p : directed_edges) {
			adyList[uf.findSet(p.first)].insert(uf.findSet(p.second));
		}

		state.assign(n, NUEVO);
		for (int i = 0; i < n && ok; ++i) {
			if (state[i] == NUEVO && hasCycle(i)) ok = false;
		}
		if (!ok) cout << "inconsistent\n";
		else cout << "consistent\n";
	}

	return 0;
}