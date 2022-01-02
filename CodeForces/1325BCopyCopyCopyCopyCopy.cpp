#include <iostream>
#include <unordered_set>

int main() {
	int T, n, x, sol;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> n;
		sol = 0;
		std::unordered_set<int> conj;
		for (int j = 0; j < n; ++j) {
			std::cin >> x;
			if (conj.count(x) == 0) {
				conj.insert(x);
				++sol;
			}
		}
		std::cout << sol << '\n';
	}
return 0;
}