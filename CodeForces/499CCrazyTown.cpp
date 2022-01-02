#include <iostream>

using namespace std;
#define ll long long

int main() {
	ll x1, y1, x2, y2, a, b, c, s1, s2;
	int n, sol = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	while (n--) {
		cin >> a >> b >> c;
		s1 = a * x1 + b * y1 + c;
		s2 = a * x2 + b * y2 + c;
		//if home and university are on opposite semiplanes
		if ((s1 < 0 && s2 > 0) || (s2 < 0 && s1 > 0)) ++sol;
	}
	cout << sol << '\n';
	return 0;
}