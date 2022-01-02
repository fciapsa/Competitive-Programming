#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define S 10000

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, l, r, par;
	cin >> tc;
	while (tc--) {
		cin >> n;
		unordered_set<int> picks, act;
		act.insert(1 + S*n);
		for (int i = 0; i < n; ++i) {
			cin >> l >> r;
			picks.insert(l + S*r);
		}

		while (!act.empty()) {
			par = *act.begin();
			act.erase(par);

			if(par%S == par/S) cout << par % S << ' ' << par % S << ' ' << par % S << '\n';
			else if (picks.count(par % S + 1 + S * (par / S))) {
				cout << par % S << ' ' << par / S << ' ' << par%S << '\n';
				act.insert(par % S + 1 + S * (par / S));
			}
			else {
				bool found = false;
				for (int i = par % S + 1; i < par / S && !found; ++i) {
					if (picks.count(par % S + S * (i - 1)) && picks.count(i + 1 + S * (par / S))) {
						cout << par % S << ' ' << par / S << ' ' << i << '\n';
						act.insert(par % S + S * (i - 1));
						act.insert(i + 1 + S * (par / S));
						found = true;
					}
				}
				if (!found) {
					cout << par % S << ' ' << par / S << ' ' << par/S << '\n';
					act.insert(par % S + S * (par / S - 1));
				}
			}
		}
	}
	return 0;
}