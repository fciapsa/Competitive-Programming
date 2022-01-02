#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) std::cin >> v[i];
		sort(v.begin(), v.end());

		if (v.size() % 2 == 0) std::cout << v[n / 2] + v[n / 2 - 1] << '\n';
		else std::cout << 2 * v[n/2] << '\n';
	std::cin >> n;
	}
return 0;
}