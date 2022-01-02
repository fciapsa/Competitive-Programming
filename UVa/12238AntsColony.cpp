#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX_V 100000

struct par {
	int pos, depth;
	bool operator<(par const& other) const {
		return depth < other.depth;
	}
};

class SegmentTree {
	vector<par> st;
	int tam; // Numero de hojas que manejamos
public:
	// Tamano maximo que podremos guardar
	// (numero de hojas).
	// Antes de las consultas, se necesita rellenar
	// con los datos iniciales usando build().
	SegmentTree(int maxN) {
		st.assign(4 * maxN + 10, par());
	}

	par query(int a, int b) {
		return query(1, 0, tam - 1, a, b);
	}
	par query(int vertex, int L, int R, int i, int j) {
		if (i > R || j < L) {
			return {-1, MAX_V};
		}
		if (L >= i && R <= j)
			// Segmento completamente dentro de la consulta
			return st[vertex];
		int mitad = (L + R) / 2;
		return min(query(2 * vertex, L, mitad, i, j),
			query(2 * vertex + 1, mitad + 1, R, i, j));
	}

	void update(int pos, par newVal) {
		update(1, 0, tam - 1, pos, newVal);
	}
	void update(int vertex, int l, int r,
		int pos, par newVal) {
		if ((pos < l) || (r < pos)) return;
		if (l == r) {
			st[vertex] = newVal;
			return;
		}
		int m = (l + r) / 2;
		if ((l <= pos) && (pos <= m))
			update(2 * vertex, l, m, pos, newVal);
		else
			update(2 * vertex + 1, m + 1, r, pos, newVal);
		st[vertex] = min(st[2 * vertex], st[2 * vertex + 1]);
	}

	void build(vector<par> const& values, int n) {
		tam = n;
		build(values, 1, 0, n - 1);
	}
	void build(vector<par> const& values, int p, int l, int r) {
		if (l == r) {
			st[p] = values[l];
			return;
		}
		int m = (l + r) / 2;
		build(values, 2 * p, l, m);
		build(values, 2 * p + 1, m + 1, r);
		st[p] = min(st[2 * p], st[2 * p + 1]);
	}
};

vector<vector<int>> adj;
SegmentTree st(0);

int idx; // Siguiente entrada en euler y prof
int euler[2 * MAX_V - 1];
int prof[2 * MAX_V - 1]; // Prof. del nodo en euler[] (RMQ sobre el)
int first[MAX_V]; // Primera aparicion del nodo i en euler[]
void eulerTour(int u, int parent, int d) { // d = depth
	first[u] = idx; euler[idx] = u; prof[idx] = d; ++idx;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == parent) continue;
		eulerTour(v, u, d + 1);
		euler[idx] = u; prof[idx] = d; ++idx;
	}
}
int lca(int u, int v) {
	return euler[st.query(first[u], first[v]).pos];
}

int main() {
    std::ios::sync_with_stdio(false);
	int n, a, q, s, t, common;
	ll w;
    cin >> n;
    while (n != 0) {
		adj.assign(n, {});
		vector<ll> dist(n);//dist[0] = 0
		for (int i = 1; i < n; ++i) {
			cin >> a >> w;
			adj[a].push_back(i);
			adj[i].push_back(a);
			dist[i] = dist[a] + w;
		}

		idx = 0;
		eulerTour(0, 0, 0);
		vector<par> values(idx);
		for (int i = 0; i < idx; ++i) {
			values[i] = { i, prof[i] };
		}
		st = SegmentTree(idx);
		st.build(values, idx);

		cin >> q >> s >> t;
		if (first[s] > first[t]) swap(s, t);
		--q;
		common = lca(s, t);
		cout << dist[s] + dist[t] - 2 * dist[common];
		while (q--) {
			cin >> s >> t;
			if (first[s] > first[t]) swap(s, t);
			common = lca(s, t);
			cout << ' ' << dist[s] + dist[t] - 2 * dist[common];
		}
		cout << '\n';
    cin >> n;
    }
    return 0;
}