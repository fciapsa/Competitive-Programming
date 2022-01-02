#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) std::cin >> v[i];
		sort(v.begin(), v.end());

		std::unordered_set<int> conj;
		std::vector<int> sol;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				auto par = conj.insert(v[i] - v[j]);
				if (par.second) sol.push_back(v[i] - v[j]);
			}
		}
		sort(sol.begin(), sol.end());
		
		std::cout << sol[0];
		for (int i = 1; i < sol.size(); ++i) {
			std::cout << ' ' << sol[i];
		}
		std::cout << '\n';

	std::cin >> n;
	}
return 0;
}