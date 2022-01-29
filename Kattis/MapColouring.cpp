#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<vector<int>> ady;
vector<int> color;
int c, maxc;

bool posible(int act) {
	if (act == c) return true;

	vector<bool> disp(maxc, true);
	for (int v : ady[act]) {
		if (color[v] != -1) disp[color[v]] = false;
	}

	for (int i = 0; i < maxc; ++i) {
		if (disp[i]) {
			color[act] = i;
			if (posible(act + 1)) return true;
			color[act] = -1;
		}
	}

	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc, b, x1, x2;
	cin >> tc;
	while (tc--) {
		cin >> c >> b;
		ady.assign(c, {});
		if (b == 0) {
			cout << 1 << '\n';
			continue;
		}
		while (b--) {
			cin >> x1 >> x2;
			ady[x1].push_back(x2);
			ady[x2].push_back(x1);
		}

		maxc = 2;
		color.assign(c, -1);
		if (posible(0)) cout << 2 << '\n';
		else {
			maxc = 3;
			color.assign(c, -1);
			if (posible(0)) cout << 3 << '\n';
			else {
				maxc = 4;
				color.assign(c, -1);
				if (posible(0)) cout << 4 << '\n';
				else cout << "many\n";
			}
		}
	}

return 0;
}