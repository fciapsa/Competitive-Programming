#include <iostream>
#include <vector>

int main() {
	int T, min, n, x;
	bool ok;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		min = 100;
		std::cin >> n;
		std::vector<int> v(n);
		for (int j = 0; j < n; ++j) {
			std::cin >> x;
			if (x < min)min = x;
			v[j] = x;
		}
		ok = true;
		for (int j = 0; j < n && ok; ++j) {
			v[j] -= min;
			if (v[j] % 2 != 0) ok = false;
		}

		if (ok) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
return 0;
}