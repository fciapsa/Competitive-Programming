#include <bits/stdc++.h>

using namespace std;
#define ll long long

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
			return 0;
		}
		if (L >= i && R <= j)
			// Segmento completamente dentro de la consulta
			return st[vertex];
		int mitad = (L + R) / 2;
		return query(2 * vertex, L, mitad, i, j) +
			query(2 * vertex + 1, mitad + 1, R, i, j);
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
		st[vertex] = st[2 * vertex] + st[2 * vertex + 1];
	}

	void build(vector<int> const& values, int n) {
		tam = n;
		build(values, 1, 0, n - 1);
	}
	void build(vector<int> const& values, int p, int l, int r) {
		if (l == r) {
			st[p] = values[l];
			return;
		}
		int m = (l + r) / 2;
		build(values, 2 * p, l, m);
		build(values, 2 * p + 1, m + 1, r);
		st[p] = st[2 * p] + st[2 * p + 1];
	}
};

int main() {
    std::ios::sync_with_stdio(false);
	int n, x, y, r, k = 1;
	bool first = true;
	string s;
    cin >> n;
	SegmentTree sgt(200001);
    while (n != 0) {
        vector<int> vr(n + 1);
        for (int i = 1; i <= n; ++i) cin >> vr[i];

		sgt.build(vr, n+1);
		if (first) first = false;
		else cout << '\n';
		cout << "Case " << k++ << ":\n";
		cin >> s;
		while (s != "END") {
			cin >> x;
			if (s == "S") {
				cin >> r;
				sgt.update(x, r);
			}
			else {
				cin >> y;
				cout << sgt.query(x, y) << '\n';
			}
			cin >> s;
		}
    cin >> n;
    }
    return 0;
}