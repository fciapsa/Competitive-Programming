#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> v;

ll inversiones(ll ini, ll fin) {
	if (ini == fin) return 0;
	if (ini == fin - 1) {
		if (v[ini] > v[fin]) {
			swap(v[ini], v[fin]);
			return 1;
		}
		return 0;
	}

	ll m = (ini + fin) / 2;
	ll ret = inversiones(ini, m);
	ret += inversiones(m + 1, fin);
	ll ind = 0, i = ini, j = m + 1;
	vector<int> aux(fin - ini + 1);
	while (i <= m && j <= fin) {
		if (v[i] <= v[j]) {
			aux[ind] = v[i];
			++i;
		}
		else {
			ret += (m - i + 1);
			aux[ind] = v[j];
			++j;
		}
		++ind;
	}
	while (i <= m) {
		aux[ind] = v[i];
		++ind; ++i;
	}
	while (j <= fin) {
		aux[ind] = v[j];
		++ind; ++j;
	}

	for (int k = ini; k <= fin; ++k) v[k] = aux[k - ini];
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n) {
		v.assign(n, 0);
		for (int i = 0; i < n; ++i) cin >> v[i];
		cout << inversiones(0, n - 1) << '\n';
		cin >> n;
	}
	return 0;
}