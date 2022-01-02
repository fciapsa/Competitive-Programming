#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-9;
const double PI = acos(-1);

using T = ll;
//bool lt(double a, double b) { return a - EPS < b; };
//bool eq(double a, double b) { return fabs(a - b) < EPS; }

//using T = int;
//bool lt(int a, int b) { return a < b; }
//bool eq(int a, int b) { return a == b; }

struct pt {
	T x, y;
	ll h;
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

T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }

double angle(pt v, pt w) {
	double cosTheta = dot(v, w) / abs(v) / abs(w);
	return acos(max(-1.0, min(1.0, cosTheta)));
}

T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }

// ORDENACIÓN POLAR

bool half(pt p) { // true if in blue half
	assert(p.x != 0 || p.y != 0); // the argument of (0,0) is undefined
	return p.y > 0 || (p.y == 0 && p.x < 0);
}

void polarSort(vector<pt>& v) {
	sort(v.begin(), v.end(), [](pt v, pt w) {
		return make_tuple(half(v), 0, sq(v)) < make_tuple(half(w), cross(v, w), sq(w));
		});
}

struct ord {
	bool operator()(pt const& p1, pt const& p2) {
		return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
	}
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, k = 1;
	ll max;
    cin >> n;
    while (n != 0) {
		vector<pt> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i].x >> v[i].y >> v[i].h;
		polarSort(v);

		max = v[0].h;
		vector<pt> sol;
		for (int i = 1; i < n; ++i) {
			if (cross(v[i-1],v[i]) == 0) {
				if (v[i].h <= max) sol.push_back(v[i]);
				else max = v[i].h;
			}
			else max = v[i].h;
		}

		cout << "Data set " << k++ << ":\n";
		if (sol.size() == 0) cout << "All the lights are visible.\n";
		else {
			sort(sol.begin(), sol.end(), ord());
			cout << "Some lights are not visible:\n";
			for (int i = 0; i < sol.size() - 1; ++i) cout << "x = " << sol[i].x << ", y = " << sol[i].y << ";\n";
			cout << "x = " << sol[sol.size()-1].x << ", y = " << sol[sol.size()-1].y << ".\n";
		}

    cin >> n;
    }
    return 0;
}