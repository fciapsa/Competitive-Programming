#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll inversiones(vector<ll>& v, int ini, int fin) {
	if (ini == fin) return 0;
	if (ini == fin - 1) {
		if (v[ini] > v[fin]) {
			swap(v[ini], v[fin]);
			return 1;
		}
		return 0;
	}

	ll m = (ini + fin) / 2;
	ll ret = inversiones(v, ini, m);
	ret += inversiones(v, m + 1, fin);

	ll i = ini, j = m + 1, ind = 0;
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
		++i; ++ind;
	}
	while (j <= fin) {
		aux[ind] = v[j];
		++j; ++ind;
	}

	for (int k = ini; k <= fin; ++k) v[k] = aux[k - ini];
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	ll n, x;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	unordered_map<int, int> mp;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		mp[x] = i;
	}
	for(int i = 0; i < n; ++i) v[i] = mp[v[i]];

	x = inversiones(v, 0, n - 1);
	if (x % 2) cout << "Impossible\n";
	else cout << "Possible\n";
	return 0;
}