#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int n, x;
	bool first;
	cin >> n;
	while (n) {
		vector<int> count(100);
		for (int i = 0; i < n; ++i) {
			cin >> x;
			++count[x];
		}
		first = true;
		for (int i = 1; i < 100; ++i) {
			while (count[i]) {
				if (first) first = false;
				else cout << ' ';
				cout << i;
				--count[i];
			}
		}
		cout << '\n';
    cin >> n;
	}
	return 0;
}