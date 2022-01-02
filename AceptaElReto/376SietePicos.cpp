#include <iostream>
#include <vector>

int main() {
	int n, sol;
	std::cin >> n;
	while (n != 0) {
		sol = 0;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)std::cin >> v[i];
		--n;
		if (v[1] < v[0] && v[n] < v[0]) ++sol;
		for (int i = 1; i < n; ++i) {
			if (v[i + 1] < v[i] && v[i - 1] < v[i])++sol;
		}
		if (v[n - 1] < v[n] && v[0] < v[n]) ++sol;
		std::cout << sol << '\n';
	std::cin >> n;
	}
return 0;
}