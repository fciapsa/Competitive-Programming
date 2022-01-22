#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
	vector<int> st;
	int tam; // Numero de hojas que manejamos
public:
	// Tamano maximo que podremos guardar
	// (numero de hojas).
	// Antes de las consultas, se necesita rellenar
	// con los datos iniciales usando build().
	SegmentTree(int maxN) {
		st.assign(4 * maxN + 10, 0);
	}

	int query(int a, int b) {
		return query(1, 0, tam - 1, a, b);
	}
	int query(int vertex, int L, int R, int i, int j) {
		if (i > R || j < L) {
			return 100001;
		}
		if (L >= i && R <= j)
			// Segmento completamente dentro de la consulta
			return st[vertex];
		int mitad = (L + R) / 2;
		return min(query(2 * vertex, L, mitad, i, j),
			query(2 * vertex + 1, mitad + 1, R, i, j));
	}

	void update(int pos, int newVal) {
		update(1, 0, tam - 1, pos, newVal);
	}
	void update(int vertex, int l, int r,
		int pos, int newVal) {
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

	void build(vector<int> const& values, int n) {
		tam = n;
		build(values, 1, 0, n - 1);
	}
	void build(vector<int> const& values, int p,
		int l, int r) {
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

struct eng {
	int x, y, z;
	bool operator<(eng const& other)const {
		return z < other.z;
	}
};

int main() {
	ios::sync_with_stdio(false);

	int tc, n, sol;
	cin >> tc;
	SegmentTree st(100001);
	while (tc--) {
		cin >> n;
		st.build(vector<int>(n + 1, n + 1), n+1);

		vector<eng> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i].x >> v[i].y >> v[i].z;
		sort(v.begin(), v.end());

		sol = 0;
		for (int i = 0; i < n; ++i) {
			if (st.query(0, v[i].x) > v[i].y) ++sol;
			st.update(v[i].x, v[i].y);
		}

		cout << sol << '\n';
	}

	return 0;
}
