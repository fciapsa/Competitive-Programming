#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long int;

int main() {
	ll n, inif, finf, inic, finc, sum, anillos, x, pos;
	cin >> n;
	while (cin) {
		if (n % 2 == 0) anillos = n / 2;
		else anillos = n / 2 + 1;

		vector<ll> sumas(anillos, 0);
		for (ll i = 0; i < n; ++i) {
			for (ll j = 0; j < n; ++j) {
				cin >> x;
				pos = min(i, min(j, min(n - i-1, n - j-1)));
				sumas[pos] += x;
			}
		}

		cout << sumas[anillos - 1];
		for (int i = anillos - 2; i >= 0; --i) cout << ' ' << sumas[i];
		cout << '\n';

	cin >> n;
	}

return 0;
}