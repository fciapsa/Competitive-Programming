#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define NADA 0
#define TOCADO 1
#define HUNDIDO 2

void rec(int v, vector<int>& grado, vector<int>& estado, vector<vector<int>> const&adyList) {
	if (grado[v] == 1 && estado[v] != HUNDIDO) {
		estado[v] = HUNDIDO;
		for (int w : adyList[v]) {
			if (estado[w] != HUNDIDO) {
				--grado[w];
				rec(w, grado, estado, adyList);
			}
		}
	}
	else if (grado[v] > 1) estado[v] = TOCADO;
}

int rec2(int v, int vParent, priority_queue<int> &pq,vector<int> const& estado, 
	     vector<vector<int>> const& adyList) {
	vector<int> hijos;
	for (int w : adyList[v]) {
		if(w != vParent && estado[w] == HUNDIDO) hijos.push_back(rec2(w, v, pq, estado, adyList));
	}

	if (hijos.size() == 0) return 1;
	else if (estado[v] == TOCADO) {
		for (int i = 0; i < hijos.size(); ++i) pq.push(hijos[i]);
		return 0;
	}
	else {
		sort(hijos.begin(), hijos.end());
		for (int i = 0; i < hijos.size() - 1; ++i) pq.push(hijos[i]);
		return 1 + hijos[hijos.size() - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, m, k, a, b, sol;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k;

		vector<vector<int>> adyList(n);
		vector<int> grado(n);
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			--a;
			--b;
			adyList[a].push_back(b);
			adyList[b].push_back(a);
			++grado[a];
			++grado[b];
		}

		vector<int> estado(n, NADA);
		for (int i = 0; i < n; ++i) {
			if (grado[i] == 1 && estado[i] != HUNDIDO) {
				estado[i] = HUNDIDO;
				for (int w : adyList[i]) {
					if (estado[w] != HUNDIDO) {
						--grado[w];
						rec(w, grado, estado, adyList);
					}
				}
			}
		}

		sol = 0;
		priority_queue<int> pq;
		for (int i = 0; i < n; ++i) {
			if (estado[i] == TOCADO) {
				rec2(i, -1, pq, estado, adyList);
			}
			if (estado[i] != HUNDIDO) ++sol;
		}

		while (!pq.empty() && k--) {
			sol += pq.top();
			pq.pop();
		}

		cout << n-sol << '\n';
	}
	return 0;
}
