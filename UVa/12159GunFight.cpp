#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct tower {
	int x, y, p;
	int dist2(tower const& other)const {
		return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
	}
};

const double EPS = 1e-9;
const double PI = acos(-1);

using T = int;
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

	bool operator==(pt o) const { return x == o.x && y == o.y; }
	bool operator!=(pt o) const { return !(*this == o); }

	bool operator<(pt o) const { // sort points lexicographically
		if (x == o.x) return y < o.y;
		return x < o.x;
	}
};


T sq(pt v) { return v.x * v.x + v.y * v.y; }
double abs(pt v) { return sqrt(sq(v)); }

ostream& operator<<(ostream& os, pt p) {
	return os << "(" << p.x << "," << p.y << ")";
}

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

//Maximum Cardinality Bipartite Matching O(VE) ~n^3
//Maximum Independent Set = V - MCBM
//Min Vertex Cover = MCBM
int M, N;//M parte izquierda, N parte derecha
vector<vector<int>> grafo; // dirigido, tamaño M
vector<int> match, vis;
int aug(int l) {//devuelve 1 si encuentra un augmenting path
				//para el matching M representado en match
	if (vis[l]) return 0;
	vis[l] = 1;
	for (auto r : grafo[l]) {
		if (match[r] == -1 || aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int berge_mcbm() {
	int mcbm = 0;
	match.assign(N, -1);
	for (int l = 0; l < M; ++l) {
		vis.assign(M, 0);
		mcbm += aug(l);
	}
	return mcbm;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n, a, b, r, side, k = 1;
	cin >> n;
	while (n != 0) {
		vector<tower> v(n+1);
		for (int i = 1; i <= n; ++i) cin >> v[i].x >> v[i].y >> v[i].p;

		cin >> a >> b >> r;
		pt t1 = pt({ v[a].x,v[a].y });
		pt t2 = pt({ v[b].x , v[b].y });
		r *= r;
		vector<tower> v1, v2;
		for (int i = 1; i <= n; ++i) {
			if (v[i].p > 0) {
				side = orient(t1, t2, pt({ v[i].x,v[i].y }));
				if (side < 0) v1.push_back(v[i]);
				else v2.push_back(v[i]);
			}
		}

		if (v2.size() < v1.size()) swap(v1, v2);
		M = v1.size();
		N = v2.size();
		grafo.assign(M, {});
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (v1[i].dist2(v2[j]) <= r && v1[i].p > v2[j].p) grafo[i].push_back(j);
			}
		}

		cout << "Case " << k++ << ": " << berge_mcbm() << '\n';

    cin >> n;
	}
	return 0;
}