#include <iostream>
#include <algorithm>

int main() {
	int ini, p1, p2, p3, ans;
	std::cin >> ini >> p1 >> p2 >> p3;
	while (p1 != p2) {
		ans = 720;
		if (p1 >= ini) ans += (ini + 40 - p1) * 9;
		else ans += (ini - p1) * 9;
		ans += 360;
		if (p2 > p1) ans += (p2 - p1) * 9;
		else ans += (40 - p1 + p2) * 9;
		if (p2 > p3) ans += (p2 - p3) * 9;
		else ans += (p2 + 40 - p3) * 9;

		std::cout << ans << '\n';
	std::cin >> ini >> p1 >> p2 >> p3;
	}
return 0;
}