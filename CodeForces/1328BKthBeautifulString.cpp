#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	int t, n, k, pos1, pos2, i;
	std::cin >> t;
	for (int m = 0; m < t; ++m) {
		std::cin >> n >> k;
		--k;
		pos1 = n - 1;
		pos2 = n;
		i = 1;
		while (k >= i) {
			k -= i;
			--pos1;
			++i;
		}
		pos2 -= k;
		for (int j = 1; j <= n; ++j) {
			if (j == pos1 || j == pos2) std::cout << 'b';
			else std::cout << 'a';
		}
		std::cout << '\n';
	}
return 0;
}