#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	double h, m, d1, d2, ans;
	char c;
	cin >> h >> c >> m;
	while (h != 0) {
		d1 = (h + m / 60) * 30;
		if (d1 >= 360) d1 -= 360;
		d2 = m * 6;
		if (d1 >= d2) ans = min(d1 - d2, d2 + 360 - d1);
		else ans = min(d2 - d1, d1 + 360 - d2);
		cout << fixed << setprecision(3) << ans << '\n';
		cin >> h >>c >> m;
	}

return 0;
}