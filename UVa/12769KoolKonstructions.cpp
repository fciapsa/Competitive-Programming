#include <bits/stdc++.h>

using namespace std;
#define ll long long

class SegmentTree {
	vector<int> st;
	vector<int> lazy;
	int tam; // Numero de hojas que manejamos

	void setLazyUpdate(int vertex, int value) {
		// Mezclamos
		// Importante +=: el nodo podria tener
		// otras operaciones pendientes anteriores
		lazy[vertex] += value;
	}

	void pushLazyUpdate(int vertex, int L, int R) {
		st[vertex] += (R - L + 1) * lazy[vertex];
		if (L != R) {
			// Tenemos hijos
			int m = (L + R) / 2;
			setLazyUpdate(2 * vertex, lazy[vertex]);
			setLazyUpdate(2 * vertex + 1, lazy[vertex]);
		}
		lazy[vertex] = 0;
	}

public:
	// Tamano maximo que podremos guardar
	// (numero de hojas).
	// Antes de las consultas, se necesita rellenar
	// con los datos iniciales usando build().
	SegmentTree(int maxN) {
		st.assign(4 * maxN + 10, 0);
		lazy.assign(4*maxN + 10, 0);
	}

	int query(int a, int b) {
		return query(1, 0, tam - 1, a, b);
	}
	int query(int vertex, int L, int R, int i, int j) {
		pushLazyUpdate(vertex, L, R);

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

	void updateRange(int a, int b, int op) {
		updateRange(1, 0, tam - 1, a, b, op);
	}
	void updateRange(int vertex, int L, int R,
		int a, int b, int op) {
		// Resolvemos posibles operaciones pendientes
		pushLazyUpdate(vertex, L, R);
		if ((b < L) || (R < a)) return;
		// ¿Intervalo afectado por completo?
		if ((a <= L) && (R <= b)) {
			// Nos aplicamos la operaci´on y propagamos la
			// pereza a los hijos. Para evitar copiar/pegar,
			// lo hacemos aplic´andonos la pereza, y luego
			// resolvi´endola
			setLazyUpdate(vertex, op);
			pushLazyUpdate(vertex, L, R);
			return;
		}
		// Intervalo no afectado por completo. No podemos
		// ser perezosos. Aplicamos la operacion en
		// los hijos
		int m = (L + R) / 2;
		updateRange(2 * vertex, L, m, a, b, op);
		updateRange(2 * vertex + 1, m + 1, R, a, b, op);
		// Combinamos
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
	int t, a, b, y;
	vector<int> values(100001, 0);
	char c;
	cin >> t;
	while (t != 0) {
		SegmentTree sgt(100001);
		sgt.build(values, 100001);

		while (t--) {
			cin >> c;
			cin >> a;
			if (c == 'B') {
				cin >> b >> y;
				sgt.updateRange(a, b, y);
			}
			else cout << sgt.query(a, a) << '\n';
		}
    cin >> t;
	}
    return 0;
}