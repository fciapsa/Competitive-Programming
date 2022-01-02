#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main() {
	int n, k = 0;
	std::string s;
	int tot, f, give;
	std::cin >> n;
	while (std::cin) {
		std::vector<std::string> names(n);
		std::unordered_map<std::string, int> id;
		for (int i = 0; i < n; ++i) {
			std::cin >> names[i];
			id[names[i]] = i;
		}

		std::vector<int> balance(n, 0);
		for (int i = 0; i < n; ++i) {
			std::cin >> s >> tot >> f;
			if (f != 0) {
				balance[id[s]] -= (tot - tot % f);
				give = tot / f;
				for (int j = 0; j < f; ++j) {
					std::cin >> s;
					balance[id[s]] += give;
				}
			}
		}

		if (k != 0) std::cout << '\n';
		for (int i = 0; i < n; ++i) std::cout << names[i] << ' ' << balance[i] << '\n';

		std::cin >> n;
		++k;
	}
return 0;
}