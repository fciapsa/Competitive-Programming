#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-6;
const double PI = acos(-1);

using T = double;
//bool lt(double a, double b) { return a - EPS < b; };
//bool eq(double a, double b) { return fabs(a - b) < EPS; }

//using T = int;
//bool lt(int a, int b) { return a < b; }
//bool eq(int a, int b) { return a == b; }

struct pt {
	T x, y;
	pt operator+(pt p) const { return { x + p.x, y + p.y }; }
	pt operator-(pt p) const { return { x - p.x, y - p.y }; }
	pt operator*(T d) const { return { x * d, y * d }; }
	pt operator/(T d) const { return { x / d, y / d }; } // only for floating-point

	bool operator==(pt o) const { return fabs(x-o.x) < EPS && fabs(y - o.y) < EPS; }
	bool operator!=(pt o) const { return !(*this == o); }

	bool operator<(pt o) const { // sort points lexicographically
		if (fabs(x - o.x) < EPS) return y < o.y;
		return x < o.x;
	}
};

T sq(pt v) { return v.x * v.x + v.y * v.y; }
double abs(pt v) { return sqrt(sq(v)); }

double dist(pt a, pt b) { // Euclidean distance
	return hypot(a.x - b.x, a.y - b.y);
}

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

// rotate 90º counterclockwise
pt perp(pt p) { return { -p.y, p.x }; }

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

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    double l, h, sol;
    cin >> n;
    while (cin) {
        cin >> l >> h;

		line left = line({ 0,0 }, { 0,h });
		line right = line({l,0}, {l,h});
		vector<pt> inis(n), fins(n);
		for (int i = 0; i < n; ++i) {
			cin >> inis[i].y >> fins[i].x >> fins[i].y;
			if (i % 2) inis[i].x = l;
			else inis[i].x = 0;
		}

		sol = right.dist(fins[0]);
		for (int i = 1; i < n; ++i) {
			line act = line({ inis[i], fins[i] });

			pt proy = act.proj(fins[i - 1]);
			if ((i % 2 && proy.x >= fins[i].x) || (i % 2 == 0 && proy.x <= fins[i].x))
				sol = fmin(sol, act.dist(fins[i - 1]));
			else sol = fmin(sol, dist(fins[i - 1], fins[i]));

			if (i % 2) sol = fmin(sol, left.dist(fins[i]));
			else sol = fmin(sol, right.dist(fins[i]));
		}

		cout << fixed << setprecision(2) << sol << '\n';

    cin >> n;
    }
    return 0;
}