#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const vector<int> acum = { 0,0,31,60,91,121,152,182,213,244,274,305,335 };

struct fecha {
	int dd, mm;
	bool operator<(fecha const& other)const {
		return mm < other.mm || (mm == other.mm && dd < other.dd);
	}
};

struct rango {
	fecha ini, fin;
	bool operator<(rango const& other) const {
		return fin < other.fin;
	}
};

int main() {
	int n, dd1, mm1, dd2, mm2, sol;
	char c;
	bool ok;
	cin >> n;
	while (std::cin) {

		std::vector<rango> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> dd1 >> c >> mm1 >> dd2 >> c >> mm2;
			v[i] = { {dd1,mm1},{dd2,mm2} };
		}

		sort(v.begin(), v.end());

		sol = 0;
	    vector<int> dias(367);
		for (int i = 0; i < n; ++i) {
			dd1 = v[i].ini.dd + acum[v[i].ini.mm];
			dd2 = v[i].fin.dd + acum[v[i].fin.mm];
			ok = true;
			for (int i = dd1; i <= dd2 && ok; ++i) {
				ok = dias[i] < 4;
			}
			
			if (ok) {
				++sol;
				for (int i = dd1; i <= dd2; ++i) ++dias[i];
			}
		}

		cout << sol << '\n';
	cin >> n;
	}

return 0;
}