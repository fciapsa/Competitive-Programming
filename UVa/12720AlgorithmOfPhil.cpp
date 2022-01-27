#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define MOD 1000000007

int c2i(char c) {
	return int(c) - int('0');
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc, s, i, j, k = 1;
	string a;
	cin >> tc;
	while (tc--) {
		cin >> a;
		if (a.size() % 2) {
			i = j = a.size() / 2;
			s = c2i(a[i]);
			--i;
			++j;
		}
		else {
			i = a.size() / 2 - 1;
			j = a.size() / 2;
			s = 0;
		}
		while (i >= 0) {
			if (c2i(a[i]) >= c2i(a[j])) {
				s = ((s << 1) | c2i(a[i])) % MOD;
				s = ((s << 1) | c2i(a[j])) % MOD;
			}
			else {
				s = ((s << 1) | c2i(a[j])) % MOD;
				s = ((s << 1) | c2i(a[i])) % MOD;
			}
			--i;
			++j;
		}
		cout << "Case #" << k++ << ": " << s << '\n';
	}
	return 0;
}