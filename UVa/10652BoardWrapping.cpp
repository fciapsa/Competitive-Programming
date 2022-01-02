#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-9;
const double PI = acos(-1);

#define conv PI/180.0

struct board {
    double x, y, w, h, phi;
};

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

	bool operator==(pt o) const { return fabs(x - o.x) < EPS && fabs(y - o.y) < EPS; }
	bool operator!=(pt o) const { return !(*this == o); }

	bool operator<(pt o) const { // sort points lexicographically
		if (fabs(x -  o.x) < EPS) return y < o.y;
		return x < o.x;
	}
};

T sq(pt v) { return v.x * v.x + v.y * v.y; }
double abs(pt v) { return sqrt(sq(v)); }

double dist(pt a, pt b) { // Euclidean distance
	return hypot(a.x - b.x, a.y - b.y);
}
T dist2(pt a, pt b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// PRODUCTOS

T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }

bool isPerp(pt v, pt w) { return dot(v, w) == 0; }

double angle(pt v, pt w) {
	double cosTheta = dot(v, w) / abs(v) / abs(w);
	return acos(max(-1.0, min(1.0, cosTheta)));
}

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

// positivo/cero/negativo: c a la izquieda/sobre/derecha de a-b
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }

bool inAngle(pt a, pt b, pt c, pt p) {
	assert(orient(a, b, c) != 0);
	if (orient(a, b, c) < 0) swap(b, c);
	return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}

double orientedAngle(pt a, pt b, pt c) {
	if (orient(a, b, c) >= 0)
		return angle(b - a, c - a);
	else
		return 2 * PI - angle(b - a, c - a);
}

// TRANSFORMACIONES

pt translate(pt v, pt p) { return p + v; }

// scale p by a certain factor around a center c
pt scale(pt c, double factor, pt p) {
	return c + (p - c) * factor;
}

// rotate p by a certain angle a counter-clockwise around origin
pt rotate(pt p, double a) {
	return { p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a) };
}

// rotate 90º counterclockwise
pt perp(pt p) { return { -p.y, p.x }; }

// ENVOLVENTE CONVEXA

// para aceptar puntos colineales cambia a >=
// returns true if point r is on the left side of line pq
bool ccw(pt p, pt q, pt r) {
	return orient(p, q, r) > 0;
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

// POLIGONOS, el primer y último puntos coinciden

double areaTriangle(pt a, pt b, pt c) {
	return abs(cross(b - a, c - a)) / 2.0;
}

double areaPolygon(vector<pt> const& p) {
	double area = 0.0;
	for (int i = 0, n = int(p.size()) - 1; i < n; ++i) {
		area += cross(p[i], p[i + 1]);
	}
	return abs(area) / 2.0;
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n;

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<board> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i].x >> v[i].y >> v[i].w >> v[i].h >> v[i].phi;
			v[i].phi = -v[i].phi;
		}

		pt v1, v2, v3, v4, c;
		vector<pt> pts;
		for (int i = 0; i < n; ++i) {
			c = { v[i].x, v[i].y };
			v1 = pt({-v[i].w / 2, v[i].h / 2});
			v2 = pt({ v[i].w / 2, v[i].h / 2 });
			v3 = pt({ v[i].w / 2, -v[i].h / 2 });
			v4 = pt({ -v[i].w / 2, -v[i].h / 2 });
			v1 = rotate(v1, v[i].phi * conv);
			v2 = rotate(v2, v[i].phi * conv);
			v3 = rotate(v3, v[i].phi * conv);
			v4 = rotate(v4, v[i].phi * conv);
			v1 = translate(c, v1);
			v2 = translate(c, v2);
			v3 = translate(c, v3);
			v4 = translate(c, v4);
			pts.push_back(v1);
			pts.push_back(v2);
			pts.push_back(v3);
			pts.push_back(v4);
		}

		vector<pt> hull = convexHull(pts);
		double area = areaPolygon(hull);
		double boardsArea = 0;
		for (int i = 0; i < n; ++i) boardsArea += v[i].h * v[i].w;
		cout << fixed << setprecision(1) << boardsArea*100.0 / area  << " %\n";
    }
    return 0;
}