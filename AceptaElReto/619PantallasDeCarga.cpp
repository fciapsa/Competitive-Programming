#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int c, f;
	bool ok;
	cin >> c >> f;
	while (c != 0) {
		vector<string> mat(f);
		for (int i = 0; i < f; ++i) cin >> mat[i];
		ok = true;
		int a = 0;
		while (a < f) {
			int b = 0;
			while (b < c) {
				unordered_set<char> conj;
				for (int i = a; i < a + 8; ++i) {
					for (int j = b; j < b + 8; ++j) {
						conj.insert(mat[i][j]);
					}
				}
				if (conj.size() > 2) ok = false;
				b += 8;
			}
			a += 8;
		}

		if (ok) cout << "SI\n";
		else cout << "NO\n";
		cin >> c >> f;
	}
	return 0;
}