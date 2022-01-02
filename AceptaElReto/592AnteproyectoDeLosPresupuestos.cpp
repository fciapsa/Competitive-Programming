#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

int main() {
	ll pres, n, sol, aux, prueba, ini, fin, m;
	cin >> pres >> n;
	bool found;
	while (cin) {
		vector<ll> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.begin(), v.end());

		if (pres == 0 || n == 0) cout << "0\n";
		else {
			vector<ll> acum(n);
			acum[0] = v[0];
			for (int i = 1; i < n; ++i) acum[i] = acum[i - 1] + v[i];

			found = false;
			for (int i = n-1; i >= 0 && !found; --i) {
				aux = v[i] * (n - i);
				if (i > 0) aux += acum[i - 1];

				if (aux <= pres) {
					found = true;			
					if(aux == pres || i == n-1) sol = v[i];
					else {
						ini = v[i];
						fin = v[i + 1];

						while (true) {
							if (ini == fin) {
								sol = ini;
								break;
							}
							else if (fin - ini == 1) {
								aux = fin * (n - i - 1)+ acum[i];

								if (aux <= pres) sol = fin;
								else sol = ini;

								break;
							}
							else {
								m = (ini + fin) / 2;
								aux = m * (n - i - 1) + acum[i];

								if (aux <= pres) ini = m;
								else fin = m;
							}
						}
					}
				}
			}

			if (found) cout << sol << '\n';
			else cout << pres / n << '\n';
		}

	cin >> pres >> n;
	}

return 0;
}