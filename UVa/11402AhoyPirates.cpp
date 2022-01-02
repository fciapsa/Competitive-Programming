#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define F 0
#define E 1
#define I 2
#define NOOP 3

#define MAX_N 1024000

vector<char> pirates(MAX_N);

class SegmentTree {
	vector<int> st;
	vector<int> lazy;
	int tam; // Numero de hojas que manejamos

	void setLazyUpdate(int vertex, int value) {
		// Mezclamos
		// Importante +=: el nodo podria tener
		// otras operaciones pendientes anteriores
		switch (value) {
		case F: lazy[vertex] = F; break;
		case E: lazy[vertex] = E; break;
		case I: 
			switch (lazy[vertex]) {
			case E: lazy[vertex] = F; break;
			case F: lazy[vertex] = E; break;
			case I: lazy[vertex] = NOOP; break;
			case NOOP: lazy[vertex] = I; break;
			} break;
		}
	}

	void pushLazyUpdate(int vertex, int L, int R) {
		if (lazy[vertex] != NOOP) {
			switch (lazy[vertex]) {
			case E: st[vertex] = 0; break;
			case F: st[vertex] = (R - L +1); break;
			case I: st[vertex] = (R - L + 1) - st[vertex]; break;
			}
			if (L != R) {
				// Tenemos hijos
				int m = (L + R) / 2;
				setLazyUpdate(2 * vertex, lazy[vertex]);
				setLazyUpdate(2 * vertex + 1, lazy[vertex]);
			}
			lazy[vertex] = NOOP;
		}
	}

public:
	// Tamano maximo que podremos guardar
	// (numero de hojas).
	// Antes de las consultas, se necesita rellenar
	// con los datos iniciales usando build().
	SegmentTree(int maxN) {
		st.assign(4 * maxN + 10, 0);
		lazy.assign(4 * maxN + 10, NOOP);
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

	/*void update(int pos, int newVal) {
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
		st[vertex] = st[2 * vertex] + st[2 * vertex + 1]; //modi
	}*/

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
			// Nos aplicamos la operacion y propagamos la
			// pereza a los hijos. Para evitar copiar/pegar,
			// lo hacemos aplicandonos la pereza, y luego
			// resolviendola
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

	void build(vector<char> const& values, int n) {
		tam = n;
		build(values, 1, 0, n - 1);
	}
	void build(vector<char> const& values, int p, int l, int r) {
		if (l == r) {
			st[p] = int(values[l]) - int('0');
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
	int tc, i, m, p, q, a, b, k = 1, nq;
	char op;
	string s;
	cin >> tc;
	while (tc--) {
		cin >> m;
		i = 0;
		while (m--) {
			cin >> p >> s;
			while (p--) {
				for (int j = 0; j < s.size(); ++j) pirates[i++] = s[j];
			}
		}
		SegmentTree st(i);
		st.build(pirates, i);
		cin >> q;
		nq = 1;
		cout << "Case " << k++ << ":\n";
		while (q--) {
			cin >> op >> a >> b;
			if (op == 'S') cout << "Q" << nq++ << ": " << st.query(a, b) << '\n';
			else if (op == 'E') st.updateRange(a, b, E);
			else if (op == 'F') st.updateRange(a, b, F);
			else st.updateRange(a, b, I);
		}
	}
    return 0;
}