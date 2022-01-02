#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX_N 250001

struct pend {
	ll ini, step;
	bool isC;//step = 0 no es suficiente para distinguir entre una operacion C o acumulacion de A's y B's
};

class SegmentTree {
	vector<ll> st;
	vector<pend> lazy;
	ll tam; // Numero de hojas que manejamos

	void setLazyUpdate(ll vertex, pend cambio) {
		if (lazy[vertex].step == LLONG_MAX) lazy[vertex].step = 0;
		// Mezclamos
		// Importante +=: el nodo podria tener
		// otras operaciones pendientes anteriores
		if (cambio.isC) lazy[vertex] = cambio;
		else {
			lazy[vertex].step += cambio.step;
			lazy[vertex].ini += cambio.ini;
			//lazy[vertex].isC = false;
		}
	}

	void pushLazyUpdate(ll vertex, ll L, ll R) {
		if (lazy[vertex].step != LLONG_MAX) {
			if (lazy[vertex].isC) 
				st[vertex] = ((R - L + 1) * (lazy[vertex].ini + (R - L) * lazy[vertex].step + lazy[vertex].ini)) / 2;
			else 
				st[vertex] += ((R - L + 1) * (lazy[vertex].ini + (R - L) * lazy[vertex].step + lazy[vertex].ini)) / 2;

			if (L != R) {
				// Tenemos hijos
				ll m = (L + R) / 2;
				setLazyUpdate(2 * vertex, lazy[vertex]);
				pend cambio2 = lazy[vertex];
				cambio2.ini += (m - L + 1) * cambio2.step;
				setLazyUpdate(2 * vertex + 1, cambio2);
			}
			lazy[vertex] = { 0,LLONG_MAX, false};
		}
	}

public:
	// Tamano maximo que podremos guardar
	// (numero de hojas).
	// Antes de las consultas, se necesita rellenar
	// con los datos iniciales usando build().
	SegmentTree(ll maxN) {
		st.assign(4 * maxN + 10, 0);
		lazy.assign(4 * maxN + 10, { 0,LLONG_MAX, false});
	}

	ll query(ll a, ll b) {
		return query(1, 0, tam - 1, a, b);
	}
	ll query(ll vertex, ll L, ll R, ll i, ll j) {
		pushLazyUpdate(vertex, L, R);

		if (i > R || j < L) {
			return 0;
		}
		if (L >= i && R <= j)
			// Segmento completamente dentro de la consulta
			return st[vertex];
		ll mitad = (L + R) / 2;
		return query(2 * vertex, L, mitad, i, j) +
			query(2 * vertex + 1, mitad + 1, R, i, j);
	}

	/*void update(ll pos, ll newVal) {
		update(1, 0, tam - 1, pos, newVal);
	}
	void update(ll vertex, ll l, ll r,
		ll pos, ll newVal) {
		if ((pos < l) || (r < pos)) return;
		if (l == r) {
			st[vertex] = newVal;
			return;
		}
		ll m = (l + r) / 2;
		if ((l <= pos) && (pos <= m))
			update(2 * vertex, l, m, pos, newVal);
		else
			update(2 * vertex + 1, m + 1, r, pos, newVal);
		st[vertex] = st[2 * vertex] + st[2 * vertex + 1];
	}*/

	void updateRange(ll a, ll b, pend cambio) {
		updateRange(1, 0, tam - 1, a, b, cambio);
	}
	void updateRange(ll vertex, ll L, ll R,
		ll a, ll b, pend cambio) {
		// Resolvemos posibles operaciones pendientes
		pushLazyUpdate(vertex, L, R);
		if ((b < L) || (R < a)) return;
		// ¿intervalo afectado por completo?
		if ((a <= L) && (R <= b)) {
			// Nos aplicamos la operacion y propagamos la
			// pereza a los hijos. Para evitar copiar/pegar,
			// lo hacemos aplicandonos la pereza, y luego
			// resolviendola
			setLazyUpdate(vertex, cambio);
			pushLazyUpdate(vertex, L, R);
			return;
		}
		// intervalo no afectado por completo. No podemos
		// ser perezosos. Aplicamos la operacion en
		// los hijos
		ll m = (L + R) / 2;
		pend cambio2 = cambio;
		if (a <= m) {
			updateRange(2 * vertex, L, m, a, b, cambio);
			cambio2.ini += (m - max(L, a) + 1) * cambio2.step;
		}
		else pushLazyUpdate(2 * vertex, L, m);
		if (b > m) {
			updateRange(2 * vertex + 1, m + 1, R, a, b, cambio2);
		}
		else pushLazyUpdate(2 * vertex + 1, m + 1, R);
		// Combinamos
		st[vertex] = st[2 * vertex] + st[2 * vertex + 1];
	}

	void build(vector<ll> const& values, ll n) {
		tam = n;
		build(values, 1, 0, n - 1);
	}
	void build(vector<ll> const& values, ll p, ll l, ll r) {
		if (l == r) {
			st[p] = values[l];
			return;
		}
		ll m = (l + r) / 2;
		build(values, 2 * p, l, m);
		build(values, 2 * p + 1, m + 1, r);
		st[p] = st[2 * p] + st[2 * p + 1];
	}
};

int main() {
    std::ios::sync_with_stdio(false);
	SegmentTree st(MAX_N);
	st.build(vector<ll>(MAX_N), MAX_N);
	ll t, i, j, x;
	pend cambio;
    cin >> t;
    char op;
    while (t--) {
        cin >> op;
		if (op == 'A') {
			cin >> i >> j;
			cambio = { 1,1, false };
			st.updateRange(i, j, cambio);
		}
		else if (op == 'B') {
			cin >> i >> j;
			cambio = { j - i + 1, -1, false };
			st.updateRange(i, j, cambio);
		}
		else if (op == 'C') {
			cin >> i >> j >> x;
			cambio = { x,0 , true};
			st.updateRange(i, j, cambio);
		}
		else {
			cin >> i >> j;
			cout << st.query(i, j) << '\n';
		}
    }
    return 0;
}