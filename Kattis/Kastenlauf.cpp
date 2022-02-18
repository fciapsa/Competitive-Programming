#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct pos {
	int x, y;
	int dist(pos const& other) const {
		return abs(x - other.x) + abs(y - other.y);
	}
	bool operator==(pos const& other)const {
		return x == other.x && y == other.y;
	}
};

vector<pos> v;
vector<vector<int>> adyList;
vector<bool> vis;
int n;

bool dfs(int pos) {
	vis[pos] = true;

	for (int w : adyList[pos]) {
		if (w == n + 1) return true;
		else if (!vis[w] && dfs(w)) return true;
	}

	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		v.assign(n + 2, {});
		for (int i = 0; i <= n+1; ++i) {
			cin >> v[i].x >> v[i].y;
		}

		adyList.assign(n + 2, {});
		for (int i = 0; i < n + 2; ++i) {
			for (int j = i + 1; j < n + 2; ++j) {
				if (v[i].dist(v[j]) <= 1000) {
					adyList[i].push_back(j);
					adyList[j].push_back(i);
				}
			}
		}

		vis.assign(n + 2, false);
		if (dfs(0)) cout << "happy\n";
		else cout << "sad\n";

	}
	return 0;
}