#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, sol, aux;
	cin >> n;
	while (cin) {
		vector<int> v(pow(2, n)), pots(pow(2, n));
		for (int i = 0; i < v.size(); ++i) cin >> v[i];

		for (int i = 0; i < v.size(); ++i) {
			aux = 0;
			for (int b = 1; b < v.size(); b = b << 1) {
				aux += v[i ^ b];
			}
			pots[i] = aux;
		}

		sol = 0;
		for (int i = 0; i < v.size(); ++i) {
			for (int b = 1; b < v.size(); b = b << 1) {
				sol = max(sol, pots[i] + pots[i ^ b]);
			}
		}
		cout << sol << '\n';
		cin >> n;
	}
	return 0;
}