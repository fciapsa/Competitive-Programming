#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define EPS 1e-9

using T = double;
struct pt {
    T x, y;
    pt operator+(pt p) const {
        return { x + p.x, y + p.
y };
    }
    pt operator-(pt p) const {
        return { x - p.x, y - p.
y };
    }
    pt operator*(T d) const { return { x * d, y * d }; }
    pt operator/(T d) const {
        return { x / d, y / d };
    } // only for floating-point
    bool operator==(pt o) const {
        return x == o.x && y
            == o.y;
    }
    bool operator!=(pt o) const {
        return !(*this == o);
    }
    /*
    bool operator<(pt o) const { // sort points
    lexicographically
    if (x == o.x) return y < o.y;
    return x < o.x;
    }
    */
    bool operator<(pt o) const {
        if (fabs(x - o.x) < EPS) // 1e-9
            return y < o.y;
        return x < o.x;
    }
};

T sq(pt v) { return v.x * v.x + v.y * v.y; }
double abs(pt v) { return sqrt(sq(v)); }
double dist(pt a, pt b) { // Euclidean distance
    return hypot(a.x - b.x, a.y - b.y);
}
T dist2(pt a, pt b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y -
        b.y);
}
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }
bool isPerp(pt v, pt w) { return dot(v, w) == 0; }
double angle(pt v, pt w) { // [0..PI], deg=(rad*180)/PI
    double cosTheta = dot(v, w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

// rotate 90 counterclockwise
pt perp(pt p) { return { -p.y, p.x }; }

struct line {
    pt v; T c; // from direction vector v and offset c
    line(pt v, T c) : v(v), c(c) {} // from equation ax + by = c
        line(T a, T b, T c) : v({ b,-a }), c(c) {} // from points pand q
        line(pt p, pt q) : v(q - p), c(cross(v, p)) {}
    T side(pt p) { return cross(v, p) - c; }
    double dist(pt p) { return abs(side(p)) / abs(v); }
    pt proj(pt p) { return p - perp(v) * side(p) / sq(v); }
    // orthogonal projection
    bool cmpProj(pt p, pt q) {
        return dot(v, p) < dot(v,
            q);
    } // true si p va antes que q, respecto vec. v
};
// true if l1 and l2 intersect, intersection = out
bool inter(line l1, line l2, pt& out) {
    T d = cross(l1.v, l2.v);
    if (d == 0)
        return false;
    out = (l2.v * l1.c - l1.v * l2.c) / d; // requires floating - point coordinates
        return true;
}


double areaPolygon(vector<pt> const& p) {
    double area = 0.0;
    for (int i = 0; i < int(p.size()) - 1; ++i) {
        area += cross(p[i], p[i + 1]);
    }
    return abs(area) / 2.0;
}

void cutPolygon(pt a, pt b, vector<pt> const& P, vector<pt> &R)
{
    R.clear();
    pt c;
    for (int i = 0; i < int(P.size()) - 1; i++) {
        double left1 = cross(b - a, P[i] - a), left2 =
            cross(b - a, P[i + 1] - a);
        if (left1 >= 0)
            R.push_back(P[i]); // P[i] is on the left of ab
            if (left1 * left2 < 0) { // edge (P[i], P[i+1]) crosses line ab
                inter({ P[i], P[i + 1] }, { a, b }, c);
                R.push_back(c);
            }
    }
    if (!R.empty())
        R.push_back(R[0]); // make R’s first point = R s last point
}


int main() {
    std::ios::sync_with_stdio(false);
    double c, minX = 1e5, maxX = -1e5;
    int n, x, y;
    cin >> c >> n;
    vector<pt> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        v[i] = { (double)x, (double)y };
        minX = fmin(minX, x);
        maxX = fmax(maxX, x);
    }

    v.push_back(v[0]);
    double A = areaPolygon(v);
    int numCuts = floor(A/c);
    cout << numCuts << '\n';
    c = A / numCuts;

    double prevX = minX;
    vector<pt> corte;
    for (int i = 1; i < numCuts; ++i) {
        double l = prevX, r = maxX;

        for (int j = 0; j < 45; ++j) {
            double h = (l + r) / 2;
            cutPolygon({ h,0.0 }, { h,10.0 }, v, corte);
            double actArea = areaPolygon(corte);

            if (actArea >= i * c) {
                r = h;
                prevX = h;
            }
            else l = h;
        }

        cout << fixed << setprecision(9) << prevX << '\n';
    }

    return 0;
}