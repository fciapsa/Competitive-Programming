#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<pair<ll, ll>> v1, v2;

ll cota1(int i, int j, ll val) {
	if (i > j) return -1;

	if (i == j) {
		if (v1[i].first > val) return v1[i].second;
		else return -1;
	}

	if (i == j - 1) {
		if (v1[i].first > val) return v1[i].second;
		else if (v1[j].first > val) return v1[j].second;
		else return -1;
	}

	int m = (i + j) / 2;
	if (v1[m].first > val) return cota1(i, m, val);
	else return cota1(m + 1, j, val);
}

ll cota2(int i, int j, ll val) {
	if (i > j) return -1;

	if (i == j) {
		if (v2[i].first > val) return v2[i].second;
		else return -1;
	}

	if (i == j - 1) {
		if (v2[i].first > val) return v2[i].second;
		else if (v2[j].first > val) return v2[j].second;
		else return -1;
	}

	int m = (i + j) / 2;
	if (v2[m].first > val) return cota2(i, m, val);
	else return cota2(m + 1, j, val);
}

int main() {
	std::ios::sync_with_stdio(false);
	ll n, m, tiempo, mx, aux;
	cin >> n;
	while (cin) {
		cin >> m >> tiempo;
		v1.assign(n, { 0,0 });
		v2.assign(m, { 0,0 });

		for (int i = n-1; i >= 0; --i) cin >> v1[i].first;
		for (int i = m-1; i >= 0; --i) cin >> v2[i].first;

		if (n > 0) v1[0].second = 1;
		for (int i = 1; i < n; ++i) {
			v1[i].first += v1[i - 1].first;
			v1[i].second = i + 1;
		}
		if (m > 0) v2[0].second = 1;
		for (int i = 1; i < m; ++i) {
			v2[i].first += v2[i - 1].first;
			v2[i].second = i + 1;
		}

		if (n == 0 && m == 0) cout << "0\n";
		else if (n == 0) {
			ll pos = cota2(0, m-1, tiempo);
			if (pos != -1) {
				cout << pos - 1 << '\n';
			}
			else cout << m << '\n';
		}
		else if (m == 0) {
			ll pos = cota1(0, n-1, tiempo);
			if (pos != -1) {
                cout << pos - 1 << '\n';
			}
			else cout << n << '\n';
		}
		else {
			mx = 0;
			for (int i = 0; i < n && v1[i].first <= tiempo; ++i) {
				ll pos = cota2(0, m-1, tiempo-v1[i].first);
				if (pos != -1) {
					if (i + pos > mx) mx = i + pos;
				}
				else {
					if (i + 1 + m > mx) mx = i + 1 + m;
				}
			}
			for (int i = 0; i < m && v2[i].first <= tiempo; ++i) {
				ll pos = cota1(0, n - 1, tiempo - v2[i].first);
				if (pos != -1) {
					if (i + pos > mx) mx = i + pos;
				}
				else {
					if (i + 1 + n > mx) mx = i + 1 + n;
				}
			}

			cout << mx << '\n';
		}

		cin >> n;
	}
	return 0;
}