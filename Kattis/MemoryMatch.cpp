#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int c1, c2, paired = 0;
	string p1, p2;
	map<string, unordered_set<int>> mp;
	while (k--) {
		cin >> c1 >> c2 >> p1 >> p2;
		mp[p1].insert(c1);
		mp[p2].insert(c2);
		if (p1 == p2) { //mark that they have already been matched
			mp[p1].insert(n + 1);
			paired += 2;
		}
	}

	bool seen_all = mp.size() == n / 2;
	int ans = 0;
	for (auto kv : mp) {
		if (kv.second.size() == 2) {
			++ans; //both seen but not matched
			paired += 2;
		}
		else if (kv.second.size() == 1 && seen_all) {
			++ans;//can deduce
			paired += 2;
		}
	}
	if (paired == n - 2) ++ans;
	cout << ans << '\n';

	return 0;
}