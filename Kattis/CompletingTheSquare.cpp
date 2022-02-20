#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct par {
	int x, y;
	int dist2(par const& o) const {
		return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	vector<par> v(3);
	for (int i = 0; i < 3; ++i) cin >> v[i].x >> v[i].y;
	//let v[0] be the middle corner
	if (v[1].dist2(v[0]) == v[1].dist2(v[2])) swap(v[0], v[1]);
	else if(v[2].dist2(v[0]) == v[2].dist2(v[1])) swap(v[0], v[2]);

	par sol = v[0];
	sol.x += (v[1].x - v[0].x);
	sol.y += (v[1].y - v[0].y);
	sol.x += (v[2].x - v[0].x);
	sol.y += (v[2].y - v[0].y);
	cout << sol.x << ' ' << sol.y << '\n';

	return 0;
}