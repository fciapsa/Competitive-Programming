#include <iostream>

#define ll long long
using namespace std;

int main() {
	ll T, n, l, r, act, perLevel, levelBeg, level, max, L, R, m;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n >> l >> r;
		max = n * (n - 1) + 1;

		L = 1;
		R = n;
		while (L < R) {
			m = (L + R) / 2;
			if (m * (2 * n - 1 - m) < l) L = m + 1;
			else R = m;
		}

		perLevel = 2*(n - 1) - 2*(L-1);
		levelBeg = ((L - 1) * (2 * (n - 1) + 2 * (n - 1) - 2 * (L - 2))) / 2 + 1;
		level = L;

		act = l;
		if (act == max) std::cout << '1';
		else if (act == levelBeg + perLevel - 1) std::cout << n;
		else {
			if ((act - levelBeg) % 2 == 0) std::cout << level;
			else std::cout << (act - levelBeg) / 2 + 1 + level;
		}

		while (act < r) {
			++act;
			if (act == levelBeg + perLevel) {
				levelBeg = act;
				perLevel -= 2;
				++level;
			}

			if (act == max) std::cout << " 1";
			else if (act == levelBeg + perLevel - 1) std::cout << ' ' << n;
			else {
				if ((act - levelBeg) % 2 == 0) std::cout << ' ' << level;
				else std::cout << ' ' << (act - levelBeg) / 2 + 1 + level;
			}
		}
		std::cout << '\n';
	}

return 0;
}