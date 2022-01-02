#include <iostream>
#include <string>
#include <cctype>

int main() {
	int t, j;
	std::string s;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> s;
		j = s.size() - 1;
		if (isupper(s[0])) {
			s[0] = char(tolower(s[0]));
			s[j] = char(toupper(s[j]));
		}
		while (j >= 0) {
			std::cout << s[j];
			--j;
		}
		std::cout << '\n';
	}
return 0;
}