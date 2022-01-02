#include <iostream>
#include <set>
#include <vector>

int main() {
	long long int n, d, sol, min, aux;
	std::cin >> n;
	while (n != 0) {
		sol = 0;
		std::vector<std::set<int>> tams(22);
		std::vector<int> conejos(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> d;
			conejos[i] = d;
			tams[d].insert(i);
		}
		tams[21].insert(n);

		for (int i = 0; i < n; ++i) {
			min = n;
			for (int j = conejos[i] + 1; j <= 21; ++j) {
				auto it = tams[j].upper_bound(i);
				if (it != tams[j].end() && *it < min) min = *it;
			}
			sol += min - i;
		}

		std::cout << sol << '\n';
	std::cin >> n;
	}
return 0;
}