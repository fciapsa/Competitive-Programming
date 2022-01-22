#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	vector<ll> fibs = { 1,1 };
	int tam = 2;
	ll x = fibs[1] + fibs[0];
	while (x < 1e9) {
		fibs.push_back(x);
		++tam;
		x = fibs[tam - 1] + fibs[tam - 2];
	}

	//f_i * a + f_{i+1} * b = n
	ll tc, n, b, a, sol_a;
	bool found;
	cin >> tc;
	while (tc--) {
		cin >> n;
		found = false;
		b = 1;
		while (!found) {
			for (int i = 0; i < fibs.size()-1 && b * fibs[i+1] < n; ++i) {
				a = n - b * fibs[i + 1];
				if (a % fibs[i]) continue;
				a /= fibs[i];
				if (a <= b) {
					found = true;
					sol_a = a;
				}
			}
			if (!found) ++b;
		}

		cout << sol_a << ' ' << b << '\n';
	}
	return 0;
}