#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, x, act, mx;
	cin >> n;
	while (n != 0) {
		map<int, int> mp;
		act = mx = 0;

		while (n--) {
			cin >> x;
			if (mp.count(x)) {
				mp.erase(x);
				--act;
			}
			else {
				++mp[x];
				++act;
				if (act > mx) mx = act;
			}
		}
		cout << mx << '\n';
		cin >> n;
	}
	return 0;
}