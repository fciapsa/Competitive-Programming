#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define MAX 262144

int main() {
	std::ios::sync_with_stdio(false);
	int n, r, ronda, tam;
	ll sol;
	vector<char> act(MAX), prev(MAX);
	cin >> n >> r;
	while (n != 0) {
		for (int i = 0; i < n; ++i) cin >> act[i];

		if (r == 0) cout << "0\n";
		else {
			ronda = 1;
			tam = n;
			sol = 0;
			while (ronda <= r) {
				for (int i = 0; i < tam; i += 2) {
					if (act[i] == '1' && act[i + 1] == '1') ++sol;

					if (act[i] == '1' || act[i + 1] == '1') act[i / 2] = '1';
					else act[i / 2] = '0';
				}
				tam /= 2;
				++ronda;
			}
			cout << sol << '\n';
		}

		cin >> n >> r;
	}
	return 0;
}