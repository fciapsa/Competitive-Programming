#include <iostream>
#include <vector>

int main() {
	int t, n, k, x, notMG, notMB;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		notMG = -1;
		std::cin >> n;
		std::vector<bool> girls(n + 1, false), boys(n + 1, false);
		for (int i = 1; i <= n; ++i) {
			std::cin >> k;
			for (int j = 0; j < k; ++j) {
				std::cin >> x;
				if (!girls[i] && !boys[x]) {
					girls[i] = true;
					boys[x] = true;
				}
			}
			if (!girls[i] && notMG == -1) notMG = i;
		}
		if (notMG == -1) std::cout << "OPTIMAL\n";
		else {
			notMB = -1;
			for (int i = 1; i <= n && notMB == -1; ++i) {
				if (!boys[i]) notMB = i;
			}
			std::cout << "IMPROVE\n";
			std::cout << notMG << ' ' << notMB << '\n';
		}
	}
return 0;
}