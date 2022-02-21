#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define INF 2000000000LL

struct line {
	ll x1, y1, x2, y2;
	bool contains(int x, int y) {
		return (x - x1) * (y2 - y1) == (y - y1) * (x2 - x1);
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	if (n <= 4) cout << "success\n";
	else {
		vector<ll> vx(n);
		vector<ll> vy(n);
		for (int i = 0; i < n; ++i) cin >> vx[i] >> vy[i];

		bool ok = true;
		line l1 = { vx[0], vy[0], vx[1], vy[1] };
		line l2 = { INF, INF, INF, INF };
		for (int i = 2; i < n && ok; ++i) {
			if (l1.contains(vx[i], vy[i])) continue;

			if (l2.x1 == INF) {
				l2.x1 = vx[i];
				l2.y1 = vy[i];
			}
			else if (l2.x2 == INF) {
				l2.x2 = vx[i];
				l2.y2 = vy[i];
			}
			else if (!l2.contains(vx[i], vy[i])) ok = false;
		}
		if (ok) cout << "success\n";
		else {
			ok = true;
			l1 = { vx[0], vy[0], vx[2], vy[2] };
			l2 = { INF, INF, INF, INF };
			if (!l1.contains(vx[1], vy[1])) {
				l2.x1 = vx[1];
				l2.y1 = vy[1];
			}
			for (int i = 2; i < n && ok; ++i) {
				if (l1.contains(vx[i], vy[i])) continue;

				if (l2.x1 == INF) {
					l2.x1 = vx[i];
					l2.y1 = vy[i];
				}
				else if (l2.x2 == INF) {
					l2.x2 = vx[i];
					l2.y2 = vy[i];
				}
				else if (!l2.contains(vx[i], vy[i])) ok = false;
			}

			if(ok) cout << "success\n";
			else {
				ok = true;
				l1 = { vx[1], vy[1], vx[2], vy[2] };
				l2 = { INF, INF, INF, INF };
				if (!l1.contains(vx[0], vy[0])) {
					l2.x1 = vx[0];
					l2.y1 = vy[0];
				}
				for (int i = 2; i < n && ok; ++i) {
					if (l1.contains(vx[i], vy[i])) continue;

					if (l2.x1 == INF) {
						l2.x1 = vx[i];
						l2.y1 = vy[i];
					}
					else if (l2.x2 == INF) {
						l2.x2 = vx[i];
						l2.y2 = vy[i];
					}
					else if (!l2.contains(vx[i], vy[i])) ok = false;
				}

				if (ok) cout << "success\n";
				else cout << "failure\n";
			}
		}
	}
	return 0;
}