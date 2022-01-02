#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

ll B, P, L, N;
vector<ll> pots;

class SegmentTree {
	vector<ll> st;
	int tam; // Numero de hojas que manejamos
public:
	// Tamano maximo que podremos guardar
	// (numero de hojas).
	// Antes de las consultas, se necesita rellenar
	// con los datos iniciales usando build().
	SegmentTree(int maxN) {
		st.assign(4 * maxN + 10, 0);
	}

	ll query(int a, int b) {
		return query(1, 0, tam - 1, a, b);
	}
	ll query(int vertex, int L, int R, int i, int j) {
		if (i > R || j < L) {
			return 0;
		}
		if (L >= i && R <= j)
			// Segmento completamente dentro de la consulta
			return st[vertex];
		int mitad = (L + R) / 2, aux;////
		if (j > mitad) {
				return aux = ((pots[min(j,R) - mitad] * query(2 * vertex, L, mitad, i, j)) % P +
					query(2 * vertex + 1, mitad + 1, R, i, j)) % P;
		}
		return aux = query(2 * vertex, L, mitad, i, j);
	}

	void update(int pos, ll newVal) {
		update(1, 0, tam - 1, pos, newVal);
	}
	void update(int vertex, int l, int r,
		int pos, ll newVal) {
		if ((pos < l) || (r < pos)) return;
		if (l == r) {
			st[vertex] = newVal%P;
			return;
		}
		int m = (l + r) / 2;
		if ((l <= pos) && (pos <= m))
			update(2 * vertex, l, m, pos, newVal);
		else
			update(2 * vertex + 1, m + 1, r, pos, newVal);
		st[vertex] = ((pots[r-m] * st[2 * vertex]) % P + st[2 * vertex + 1]) % P;
	}

	void build(vector<ll> const& values, int n) {
		tam = n;
		build(values, 1, 0, n - 1);
	}
	void build(vector<ll> const& values, int p, int l, int r) {
		if (l == r) {
			st[p] = values[l]%P;
			return;
		}
		int m = (l + r) / 2;
		build(values, 2 * p, l, m);
		build(values, 2 * p + 1, m + 1, r);
		st[p] = ((pots[r-m] * st[2 * p]) % P + st[2 * p + 1]) % P;
	}
};

int main() {
    std::ios::sync_with_stdio(false);
	ll i, j, v;
    cin >> B >> P >> L >> N;
	char c;
	while(B != 0){
		pots.assign(L, 0);
		pots[0] = 1;
		for (int i = 1; i < L; ++i) pots[i] = (pots[i - 1] * B) % P;

		SegmentTree sgt(L);
		sgt.build(vector<ll>(L), L);

		while (N--) {
			cin >> c;
			if (c == 'E') {
				cin >> i >> v;
				sgt.update(i - 1, v);
			}
			else {
				cin >> i >> j;
				cout << sgt.query(i - 1, j - 1) << '\n';
			}
		}
	
		cout << "-\n";
    cin >> B >> P >> L >> N;
	}
    return 0;
}