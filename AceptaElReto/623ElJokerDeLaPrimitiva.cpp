#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc;
	string s;
	cin >> tc;
	while (tc--) {
		cin >> s;
		vector<int> v1(7), v2(7);
		for (int i = 0; i < s.size(); ++i) {
			v1[i] = int(s[i]) - int('0');
		}
		cin >> s;
		for (int i = 0; i < s.size(); ++i) {
			v2[i] = int(s[i]) - int('0');
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		bool ok = true;
		for (int i = 0; i < 7 && ok; ++i) {
			ok = v1[i] == v2[i];
		}
		if (ok) cout << "GANA\n";
		else cout << "PIERDE\n";
	}
	return 0;
}