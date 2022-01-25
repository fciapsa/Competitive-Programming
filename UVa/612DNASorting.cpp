#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct w {
	string s;
	int ord, pos;
	bool operator<(w const& other) const {
		return ord < other.ord || (ord == other.ord && pos < other.pos);
	}
};

string s;

int inversiones(int ini, int fin) {
	if (ini == fin) return 0;
	if (ini == fin - 1) {
		if (s[ini] > s[fin]) {
			swap(s[ini], s[fin]);
			return 1;
		}
		return 0;
	}

	int m = (ini + fin) / 2;
	int ret = inversiones(ini, m);
	ret += inversiones(m + 1, fin);
	vector<char> aux(fin - ini + 1);
	int i = ini, j = m + 1, ind = 0;
	while (i <= m && j <= fin) {
		if (s[i] <= s[j]) {
			aux[ind] = s[i];
			++i;
		}
		else {
			ret += (m - i + 1);
			aux[ind] = s[j];
			++j;
		}
		++ind;
	}
	while (i <= m) {
		aux[ind] = s[i];
		++ind; ++i;
	}
	while (j <= fin) {
		aux[ind] = s[j];
		++ind; ++j;
	}
	for (int k = ini; k <= fin; ++k) s[k] = aux[k-ini];

	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, m;
	bool first = true;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		vector<w> v(m);
		for (int i = 0; i < m; ++i) {
			cin >> v[i].s;
			s = v[i].s;
			v[i].pos = i;
			v[i].ord = inversiones(0, s.size() - 1);
		}
		sort(v.begin(), v.end());

		if (first) first = false;
		else cout << '\n';
		for (int i = 0; i < m; ++i) cout << v[i].s << '\n';
	}
	return 0;
}