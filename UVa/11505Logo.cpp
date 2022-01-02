#include <bits/stdc++.h>

using namespace std;
#define ll long long

const double EPS = 1e-9;
const double PI = acos(-1);
#define conv PI/180.0

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

pt translate(pt v, pt p) { return p + v; }

// rotate p by a certain angle a counter-clockwise around origin
pt rotate(pt p, double a) {
	return { p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a) };
}

int main() {
    std::ios::sync_with_stdio(false);
	int tc, n;
	double angle, var;
	string op;
	pt p, v;
    cin >> tc;
    while (tc--) {
        cin >> n;
		p = { 0,0 };
		angle = 0.0;
		while (n--) {
			cin >> op >> var;
			if (op[0] == 'f') {
				p.x += var * cos(angle * conv);
				p.y += var * sin(angle * conv);
			}
			else if (op[0] == 'b') {
				p.x -= var * cos(angle * conv);
				p.y -= var * sin(angle * conv);
			}
			else if (op[0] == 'l') angle += var;
			else angle -= var;

			if (angle >= 360) angle -= 360;
			else if (angle < 0) angle += 360;
		}

		cout << (ll)round(abs(p)) << '\n';
    }
    return 0;
}