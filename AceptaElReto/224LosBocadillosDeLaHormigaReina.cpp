#include <iostream>
#include <vector>

int main() {
	int sum, n, sol;
	bool ok;
	std::cin >> n;
	while (n != 0) {
		std::vector<int> v(n);
		sum = 0;
		for (int i = 0; i < n; ++i) {
			std::cin >> v[i];
			sum += v[i];
		}

		ok = false;
		for (int i = 0; i < n && !ok; ++i) {
			sum -= v[i];
			if (v[i] == sum) {
				sol = i+1;
				ok = true;
			}
		}

		if (ok) std::cout << "SI " << sol << '\n';
		else std::cout << "NO\n";

	std::cin >> n;
	}
return 0;
}