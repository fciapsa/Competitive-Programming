#include <iostream>
#include <string>

int main() {
	std::string s;
	int n, j, t;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		j = 0; t = 0;
		while (j < s.size()) {
			if (s[j] == '.') {
				++t;
				j += 3;
			}
			else ++j;
		}
		std::cout << t << '\n';
	}
return 0;
}