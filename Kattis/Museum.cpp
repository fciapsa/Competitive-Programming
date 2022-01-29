#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-7

using T = double;
struct pt {
	T x, y;

	pt operator-(pt p) const {
		return { x - p.x, y - p.y };
	}
	pt operator*(T d) const { return { x * d, y * d }; }
	pt operator/(T d) const {
		return { x / d, y / d };
	}
	bool operator==(pt o) const {
		return x == o.x && y == o.y;
	}
	bool operator!=(pt o) const {
		return !(*this == o);
	}
};

T sq(pt v) { return v.x * v.x + v.y * v.y; }
double abs(pt v) { return sqrt(sq(v)); }
double dist(pt a, pt b) { return hypot(a.x - b.x, a.y - b.y); }

T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

T orient(pt a, pt b, pt c) {
	return cross(b - a, c - a);
}

pt perp(pt p) { return { -p.y, p.x }; }

struct line {
	pt v; T c;
	line(pt v, T c) : v(v), c(c) {}
	line(T a, T b, T c) : v({ b,-a }), c(c) {}
	line(pt p, pt q) : v(q - p), c(cross(v, p)) {}
	T side(pt p) { return cross(v, p) - c; }
	double dist(pt p) { return abs(side(p)) / abs(v); }
	pt proj(pt p) { return p - perp(v) * side(p) / sq(v); }

	bool cmpProj(pt p, pt q) {
		return dot(v, p) < dot(v,q);
	}
};

bool inter(line l1, line l2, pt& out) {
	T d = cross(l1.v, l2.v);
	if (d == 0) return false;
	out = (l2.v * l1.c - l1.v * l2.c) / d;
	return true;
}

vector<pt> cutPolygon(pt a, pt b, vector<pt> const& P) {
	vector<pt> R;
	pt c;
	for (int i = 0; i < int(P.size()) - 1; i++) {
		double left1 = cross(b - a, P[i] - a), left2 = cross(b - a, P[i + 1] - a);
		if (left1 >= 0) R.push_back(P[i]);
		if (left1 * left2 < 0) {
			inter({ P[i], P[i + 1] }, { a, b }, c);
			R.push_back(c);
		}
	}
	if (!R.empty()) R.push_back(R[0]);
	return R;
}

bool properInter(pt a, pt b, pt c, pt d, pt& out) {
	double oa = orient(c, d, a), ob = orient(c, d, b), oc =
		orient(a, b, c), od = orient(a, b, d);
	if (oa * ob < 0 && oc * od < 0) {
		out = (a * ob - b * oa) / (ob - oa);
		return true;
	}
	return false;
}

bool inDisk(pt a, pt b, pt p) {
	return dot(a - p, b - p) <= 0;
}

bool onSegment(pt a, pt b, pt p) {
	return orient(a, b, p) == 0 && inDisk(a, b, p);
}

vector<pt> inters(pt a, pt b, pt c, pt d) {
	pt out;
	if (properInter(a, b, c, d, out)) return { out };
	vector<pt> v;
	if (onSegment(c, d, a)) v.push_back(a);
	if (onSegment(c, d, b)) v.push_back(b);
	if (onSegment(a, b, c)) v.push_back(c);
	if (onSegment(a, b, d)) v.push_back(d);
	if (v.size() == 2 && v[0] == v[1]) v.pop_back();
		return v;
}

int main() {
	ios::sync_with_stdio(false);
	int tc, l, w, ans;
	double x, y, ws;
	vector<pt> corte;
	cin >> tc;
	while (tc--) {
		cin >> l >> w;

		vector<pt> cols(2 * l + 2 * w);
		for (int i = 0; i <= w; ++i) {
			cols[i] = { 0.0, (T)i};
		}
		for (int i = w + 1, j = 1; j <= l; ++i, ++j) {
			cols[i] = { (T)j, (T)w };
		}
		for (int i = w + l + 1, j = w-1; j >= 0; ++i, --j) {
			cols[i] = { (T)l, (T)j };
		}
		for (int i = 2 * w + l + 1, j = l - 1; j > 0; ++i, --j) {
			cols[i] = { (T)j, 0.0 };
		}

		cin >> x >> y >> ws;
		vector<pt> pol = { {x,y}, {x + ws, y}, {x + ws, y + ws}, {x,y + ws}, {x,y} };

		vector<vector<int>> good(cols.size());
		for (int i = 0; i < cols.size(); ++i) {
			for (int j = i + 1; j < cols.size(); ++j) {
				corte = cutPolygon(cols[i], cols[j], pol);
				if (corte.size() != 0 && corte != pol) continue;
				good[i].push_back(j);
			}
		}

		ans = 0;
		for (int i = 0; i < good.size(); ++i) {
			for (int j = 0; j < good[i].size(); ++j) {
				for (int k = 0; k < good[good[i][j]].size(); ++k) {
					if(orient(cols[i], cols[good[i][j]], cols[good[good[i][j]][k]]) >= 0) continue;
					corte = cutPolygon(cols[good[good[i][j]][k]], cols[i], pol);
					if (corte.size() != 0 && corte != pol) continue;
					++ans;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}