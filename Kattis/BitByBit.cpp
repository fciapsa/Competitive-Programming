#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, i, j;
	string op;
	cin >> n;
	while (n) {
		vector<char> ans(32, '?');
		while (n--) {
			cin >> op >> i;
			if (op == "SET") ans[i] = '1';
			else if (op == "CLEAR") ans[i] = '0';
			else if (op == "OR") {
				cin >> j;
				if (ans[i] == '1' || ans[j] == '1') ans[i] = '1';
				else if (ans[i] == '0' && ans[j] == '0') ans[i] = '0';
				else ans[i] = '?';
			}
			else {
				cin >> j;
				if (ans[i] == '1' && ans[j] == '1') ans[i] = '1';
				else if (ans[i] == '0' || ans[j] == '0') ans[i] = '0';
				else ans[i] = '?';
			}

		}
		for (int i = 31; i >= 0; --i) cout << ans[i];
		cout << '\n';
		cin >> n;
	}
	return 0;
}