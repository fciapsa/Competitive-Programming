#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool ok;
vector<int> v;
int n;

void va(int pos, int c1, int c2) {
	if (pos == n) {
		ok = true;
		return;
	}

	if (v[pos] <= c1) va(pos + 1, c1 - v[pos], c2);
	if (v[pos] <= c2) va(pos + 1, c1, c2 - v[pos]);
}

int main() {
	std::ios::sync_with_stdio(false);
	int tam;
	cin >> tam;
	while (cin) {
		cin >> n;
		v.assign(n, 0);
		for (int i = 0; i < n; ++i) cin >> v[i];
		ok = false;
		va(0, tam, tam);
		if (ok) cout << "SI\n";
		else cout << "NO\n";

		cin >> tam;
	}
	return 0;
}