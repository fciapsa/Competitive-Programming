#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll dateToInt(ll d, ll m, ll y) {
	return 1461 * (y + 4800 + (m - 14) / 12) / 4 +
		367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
		3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 +
		d - 32075;
}

struct par {
	ll ini, fin;
};

struct ordIni {
	bool operator()(par const& p1, par const& p2) {
		return p1.ini < p2.ini;
	}
};
struct ordFin {
	bool operator()(par const& p1, par const& p2) {
		return p1.fin < p2.fin;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	ll tc, d, m, y, b, clean, hh, mm, act, ans, ind1, ind2;
	string s;
	char c;
	cin >> tc;
	while (tc--) {
		cin >> b >> clean;
		vector<par> v1(b), v2;
		for (int i = 0; i < b; ++i) {
			cin >> s >> y >> c >> m >> c >> d >> hh >> c >> mm;
			v1[i].ini = dateToInt(d, m, y)*1440 + 60 * hh + mm;
			cin >> y >> c >> m >> c >> d >> hh >> c >> mm;
			v1[i].fin = dateToInt(d, m, y)*1440 + 60 * hh + mm + clean;
		}
		v2 = v1;
		sort(v1.begin(), v1.end(), ordIni());
		sort(v2.begin(), v2.end(), ordFin());

		act = ans = ind1 = ind2 = 0;
		while (ind1 < b) {
			while (ind1 < b && v1[ind1].ini < v2[ind2].fin) {
				++act;
				++ind1;
			}
			if (act > ans) ans = act;

			if (ind1 < b) {
				while (v2[ind2].fin <= v1[ind1].ini) {
					++ind2;
					--act;
				}
			}
		}

		cout << ans << '\n';
	}
	return 0;
}