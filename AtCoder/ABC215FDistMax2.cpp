#include <bits/stdc++.h>

using namespace std;
#define ll long long

//The maximization problem of a minimum value can often be solved with a binary search

// Let us check if there is a pair with distance at least K
// min(x diff, y diff) >= K is equivalent to (x diff) >= K AND (y diff) >= K

// So there is a pair with distance more than or equal to K <====> there is a point (x_i, y_i) such that
// for points with x coord at most x_i - K the max y coord is at least y_i + K or the min y coord is at most y_i - K

//We can check this in O(N) by having points sorted by the x coordinate and performing the bynary search over K

struct par {
	int x, y;
	bool operator<(par const& other) {
		return x < other.x;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<par> pts(n);
	for (int i = 0; i < n; ++i) cin >> pts[i].x >> pts[i].y;
	sort(pts.begin(), pts.end());//sort by increasing x coord

	int ok = 0, bad = 1e9 + 1, mid, mn, mx;
	bool found;
	while (bad - ok > 1) {
		mid = (bad + ok) / 2;
		queue<par> q;
		mn = 1e9 + 1;
		mx = 0;
		found = false;
		for (par p : pts) {
			while (!q.empty()) {
				if (q.front().x > p.x - mid) break;//not far enough
				mn = min(mn, q.front().y);//accumulative min y coord
				mx = max(mx, q.front().y);//accumulative max y coord
				q.pop();
			}
			if (mn <= p.y - mid || mx >= p.y + mid) found = true;
			q.push(p);
		}

		if (found) ok = mid;
		else bad = mid;
	}

	cout << ok << '\n';

return 0;
}