#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	ll tc, hc, dc, hm, dm, k, w, a, rounds, aux;
	cin >> tc;
	while (tc--) {
		cin >> hc >> dc >> hm >> dm >> k >> w >> a;
		dc += k * w;
		rounds = (hc+dm-1) / dm;
		if ((hm+dc-1)/dc <= rounds) cout << "YES\n";
		else {
			hm -= dc * rounds;
			hc -= dm * rounds;
			while (k && hm > 0) {
				while (k && hc <= 0) {
					--k;
					hc += a;
					hm += rounds * w;
					dc -= w;
				}

				if (hc > 0) {
					aux = (hc + dm - 1) / dm;
					hm -= aux * dc;
					hc -= aux * dm;
					rounds += aux;
				}
			}

			if (hm > 0) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	return 0;
}