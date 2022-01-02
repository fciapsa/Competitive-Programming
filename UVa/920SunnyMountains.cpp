#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define EPS 1e-9
using T = double;

struct pt {
	T x, y;
	pt operator+(pt p) const { return { x + p.x, y + p.y }; }
	pt operator-(pt p) const { return { x - p.x, y - p.y }; }
	pt operator*(T d) const { return { x * d, y * d }; }
	pt operator/(T d) const { return { x / d, y / d }; } // only for floating-point

	bool operator==(pt o) const { return fabs(x - o.x) <= EPS && fabs(y - o.y) <= EPS; }
	bool operator!=(pt o) const { return !(*this == o); }

	bool operator<(pt o) const { // sort points lexicographically
		if (fabs(x - o.x) > EPS) return x < o.x;
		return y < o.y;
	}
};

double dist(pt a, pt b) { // Euclidean distance
	return hypot(a.x - b.x, a.y - b.y);
}

T sq(pt v) { return v.x * v.x + v.y * v.y; }
double abs(pt v) { return sqrt(sq(v)); }

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

// rotate 90º counterclockwise
pt perp(pt p) { return { -p.y, p.x }; }

//LINEAS

struct line {
	pt v; T c;
	// from direction vector v and offset c
	line(pt v, T c) : v(v), c(c) {}
	// from equation ax + by = c
	line(T a, T b, T c) : v({ b,-a }), c(c) {}
	// from points p and q
	line(pt p, pt q) : v(q - p), c(cross(v, p)) {}

	T side(pt p) { return cross(v, p) - c; }

	double dist(pt p) { return abs(side(p)) / abs(v); }

	line translate(pt t) { return { v, c + cross(v,t) }; }

	pt proj(pt p) { return p - perp(v) * side(p) / sq(v); }
};

bool inter(line l1, line l2, pt& out) {
	T d = cross(l1.v, l2.v);
	if (d == 0) return false;
	out = (l2.v * l1.c - l1.v * l2.c) / d; // requires floating-point coordinates
	return true;
}

int main() {
    std::ios::sync_with_stdio(false);
	int tc, n, maxy, maxind;
    double sol;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<pt> vp(n);
        for (int i = 0; i < n; ++i) cin >> vp[i].x >> vp[i].y;
		sort(vp.begin(), vp.end());

		if (n == 1) cout << "0.00\n";
		else {
			sol = dist(vp[n - 1], vp[n - 2]);
			maxy = vp[n - 2].y;
			maxind = n - 2;

			for (int i = n - 3; i >= 0; --i) {
				if (vp[i].y <= maxy) continue;

				line l1 = line(vp[i], vp[i+1]);
				line l2 = line(vp[maxind], { 0.0, (double)maxy });
				pt out;
				inter(l1, l2, out);
				sol += dist(vp[i], out);

				maxy = vp[i].y;
				maxind = i;
			}

			cout << fixed << setprecision(2) << sol << '\n';
		}
    }
    return 0;
}