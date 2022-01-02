#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
	int a, b, c, d, x, y, x1, x2, y1, y2, T, R, L, U, D, as, bs, cs, ds;
	bool canMove1, canMove2;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
		as = a; bs = b; cs = c; ds = d;
		R = x2 - x;
		L = x - x1;
		U = y2 - y;
		D = y - y1;
		if (b > a) {
			a -= std::min(a, L);
			if (R+L > 0) {
				b -= a;
				a = 0;
			}
			if (R + std::min(as,L) >= b) b = 0;
		}
		else if (a == b) {
			if (R+L > 0) {
				a = 0; 
				b = 0;
			}
		}
		else {//a > b
			b -= std::min(b, R);
			if (R+L > 0) {
				a -= b;
				b = 0;
			}
			if (std::min(R, bs) + L >= a) a = 0;
		}

		if (d > c) {
			c -= std::min(c, D);
			if (U+D > 0) {
				d -= c;
				c = 0;
			}
			if (U + std::min(cs, D) >= d) d = 0;
		}
		else if (c == d) {
			if (U+D > 0) {
				c = 0;
				d = 0;
			}
		}
		else {//c > d
			d -= std::min(d, U);
			if (U+D > 0) {
				c -= d;
				d = 0;
			}
			if (std::min(U, ds) + D >= c) c = 0;
		}

		if (a == 0 && b == 0 && c == 0 && d == 0) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
return 0;
}