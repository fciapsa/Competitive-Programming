#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct asc {
	int a, b, lvl;
	bool operator<(asc const& other)const {
		return b < other.b;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	int n, dest, ini, fin, m, hasta, ind;
	cin >> n;
	while (cin) {
		vector<asc> v(n);
		fin = 0;

		for (int i = 0; i < n; ++i) {
			cin >> v[i].a >> v[i].b >> v[i].lvl;
			if (v[i].lvl > fin) fin = v[i].lvl;
		}
		sort(v.begin(), v.end());
		dest = v[n - 1].b;

		ini = 0;
		while (ini < fin) {
			if (ini == fin - 1) {
				m = ini;

				ind = hasta = 0;
				while (ind < n) {
					if (v[ind].a <= hasta && v[ind].lvl <= m) {
						hasta = max(hasta, v[ind].b);
					}
					++ind;
				}

				if (hasta == dest) fin = ini;
				else ini = fin;
			}
			else {
				m = (ini + fin) / 2;

				ind = hasta = 0;
				while (ind < n) {
					if (v[ind].a <= hasta && v[ind].lvl <= m) {
						hasta = max(hasta, v[ind].b);
					}
					++ind;
				}

				if (hasta == dest) fin = m;
				else ini = m + 1;
			}
		}

		cout << ini << '\n';
		cin >> n;
	}
	return 0;
}