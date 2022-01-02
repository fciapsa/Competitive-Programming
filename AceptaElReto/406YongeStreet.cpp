#include <iostream>
#include <string>

int main() {
	int i, j, k, prev, T, x;
	std::string s;
	std::cin >> s;
	while(std::cin) {
		i = 0;
		prev = -1;

		while (i < s.size()) {
			while (i < s.size() && s[i] != '|') ++i;

			if (i != s.size()) {
				j = i - 1;
				k = i - 1;
				while (j > prev) {
					if (s[j] != '.') {
						if (k != j) {
							s[k] = s[j];
							s[j] = '.';
						}
						--k;
					}
					--j;
				}

				prev = i;
				++i;
			}
			else {
				j = i - 1;
				while (j > prev) {
					s[j] = '.';
					--j;
				}
			}
		}

		std::cin >> T;
		std::cin >> x;
		std::cout << s[x - 1];
		for (int t = 1; t < T; ++t) {
			std::cin >> x;
			std::cout << ' ' << s[x - 1];
		}
		std::cout << '\n';

	std::cin >> s;
	}
return 0;
}