#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, zs, ones;
	string s;
	cin >> tc;
	while (tc--) {
		cin >> s;
		if (s.size() <= 2) cout << "0\n";
		else {
			zs = ones = 0;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == '0')++zs;
				else ++ones;
			}
			if (ones > zs) cout << zs << '\n';
			else if (zs > ones) cout << ones << '\n';
			else {
				if (s[0] == '0') cout << zs - 1 << '\n';
				else cout << ones - 1 << '\n';
			}
		}
	}
	return 0;
}