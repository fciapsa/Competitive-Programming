#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct nivel {
	int ini, fin;
};

int main() {
	std::ios::sync_with_stdio(false);
	int n, accum, a, b, x, q;
	cin >> n;
	while (n != 0) {
		vector<nivel> v(n + 1);
		accum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> x;
			v[i].ini = accum;
			accum += x;
			v[i].fin = accum;
		}

		cin >> q;
		while (q--) {
			cin >> a >> b;
			cout << v[b].ini - v[a].fin << '\n';
		}

		cout << "---\n";
		cin >> n;
	}
	return 0;
}