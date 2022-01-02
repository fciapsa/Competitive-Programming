#include <iostream>
#include <map>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	int T, n, x, max;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> n;
		max = 0;
		map<int, int> map;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			++map[x];
			if (map[x] > max) max = map[x];
		}

		if (max > (int)map.size()) cout << map.size() << '\n';
		else if (max == (int)map.size()) cout << map.size() - 1 << '\n';
		else cout << max << '\n';
	}


return 0;
}