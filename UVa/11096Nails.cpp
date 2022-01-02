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

	bool operator==(pt const o) const { return fabs(x - o.x) <= EPS && fabs(y - o.y) <= EPS; }
	bool operator!=(pt o) const { return !(*this == o); }

	bool operator <(pt p) const {
		if (fabs(x - p.x) > EPS)
			return x < p.x;
		return y < p.y;
	}
};

double dist(pt a, pt b) { // Euclidean distance
	return hypot(a.x - b.x, a.y - b.y);
}

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

// positivo/cero/negativo: c a la izquieda/sobre/derecha de a-b
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

// ENVOLVENTE CONVEXA

// para aceptar puntos colineales cambia a >=
// returns true if point r is on the left side of line pq
bool ccw(pt p, pt q, pt r) {
	return orient(p, q, r) > EPS;
}

// devuelve un polígono con la envolvente convexa de una nube de puntos P.
vector<pt> convexHull(vector<pt>& P) {
	int n = int(P.size()), k = 0;
	vector<pt> H(2 * n);
	sort(P.begin(), P.end());
	// build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && !ccw(H[k - 2], H[k - 1], P[i])) --k;
		H[k++] = P[i];
	}
	// build upper hull
	for (int i = n - 2, t = k + 1; i >= 0; --i) {
		while (k >= t && !ccw(H[k - 2], H[k - 1], P[i])) --k;
		H[k++] = P[i];
	}
	H.resize(k);
	return H;
}

int main() {
    std::ios::sync_with_stdio(false);
	double sol, ini;
	int n, tc;
	cin >> tc;
    while (tc--) {
		cin >> ini >> n;
		vector<pt> vp(n);
		for (int i = 0; i < n; ++i)  cin >> vp[i].x >> vp[i].y;
		vector<pt> hull = convexHull(vp);

		sol = 0.0;
		for (int i = 1; i < hull.size(); ++i) sol += dist(hull[i], hull[i - 1]);
		sol = max(sol, ini);
		cout << fixed << setprecision(5) << sol << '\n';
    }

    return 0;
}