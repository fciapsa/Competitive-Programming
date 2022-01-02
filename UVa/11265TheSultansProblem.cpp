#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-9;
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

	bool operator==(pt o) const { return fabs(x - o.x) < EPS && fabs(y - o.y) < EPS; }
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

// LINEAS

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

// DIVISIÓN DE UN POLÍGONO

vector<pt> cutPolygon(pt a, pt b, vector<pt> const& P) {
	vector<pt> R; pt c;
	for (int i = 0; i < int(P.size()) - 1; i++) {
		double left1 = cross(b - a, P[i] - a),
			left2 = cross(b - a, P[i + 1] - a);
		if (left1 >= 0) R.push_back(P[i]);  // P[i] is on the left of ab
		if (left1 * left2 < 0) {  // edge (P[i], P[i+1]) crosses line ab
			inter({ P[i], P[i + 1] }, { a,b }, c);
			R.push_back(c);
		}
	}
	if (!R.empty())
		R.push_back(R[0]); // make R's first point = R's last point
	return R;
}

int main() {
    std::ios::sync_with_stdio(false);
	int n, k = 1;
	double w, h, x, y, x1, y1, x2, y2;
	pt a, b, fuente;
    cin >> n;
    while (cin) {
        cin >> w >> h >> x >> y;
		fuente = pt({ x,y });

        vector<pt> pol(5);
		pol[0] = pt({ 0,0 });
		pol[1] = pt({ w,0 });
		pol[2] = pt({ w,h });
		pol[3] = pt({ 0,h });
		pol[4] = pt({ 0,0 });
		for (int i = 0; i < n; ++i) {
			cin >> x1 >> y1 >> x2 >> y2;
			a = pt({ x1,y1 });
			b = pt({ x2,y2 });
			if (cross(b - a, fuente - a) >= 0) pol = cutPolygon(a, b, pol);
			else pol = cutPolygon(b, a, pol);
		}

		cout << "Case #" << k++ << ": " << fixed << setprecision(3) << areaPolygon(pol) << "\n";

    cin >> n;
    }
    return 0;
}