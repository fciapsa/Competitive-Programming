#include <iostream>
#include <string>
#include <cctype>

int main() {
	bool ok;
	int sol;
	std::string s;
	std::cin >> s;
	while (std::cin) {
		for (int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);

		ok = false;
		sol = 1;
		while(sol < s.size() && !ok) {
			if (s.size() % sol == 0) {
				ok = true;
				for (int i = sol; i < s.size() && ok; ++i) {
					ok = s[i] == s[i % sol];
				}
				if (!ok) ++sol;
			}
			else ++sol;
		}

		std::cout << sol << '\n';

	std::cin >> s;
	}
return 0;
}