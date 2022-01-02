#include <iostream>

int main() {
	int T, tot, min, act, baja, ans;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> tot >> min;
		act = tot;
		ans = 0;
		std::cin >> baja;
		while (baja != -1) {
			act -= baja;
			if (act < min) {
				++ans;
				act = tot;
			}

		std::cin >> baja;
		}
		std::cout << ans << '\n';
	}
return 0;
}