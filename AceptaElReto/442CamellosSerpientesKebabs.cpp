#include <iostream>
#include <string>
#include <cctype>

int main() {
	std::string s, op;
	std::cin >> s;
	while (std::cin) {
		std::cin >> op;
		if (isupper(s[0])) {
			if (op == "CamelCase") std::cout << s;
			else if (op == "snake_case") {
				std::cout << char(tolower(s[0]));
				for (int i = 1; i < s.size(); ++i) {
					if (isupper(s[i])) std::cout << '_' << char(tolower(s[i]));
					else std::cout << s[i];
				}
			}
			else {
				std::cout << char(tolower(s[0]));
				for (int i = 1; i < s.size(); ++i) {
					if (isupper(s[i])) std::cout << '-' << char(tolower(s[i]));
					else std::cout << s[i];
				}
			}
		}
		else {
			if (op == "CamelCase") {
				std::cout << char(toupper(s[0]));
				for (int i = 1; i < s.size(); ++i) {
					if (s[i] == '-' || s[i] == '_') {
						++i;
						if (i < s.size()) std::cout << char(toupper(s[i]));
					}
					else std::cout << s[i];
				}
			}
			else if (op == "snake_case") {
				for (int i = 0; i < s.size(); ++i) {
					if (s[i] == '-') std::cout << '_';
					else std::cout << s[i];
				}
			}
			else {
				for (int i = 0; i < s.size(); ++i) {
					if (s[i] == '_') std::cout << '-';
					else std::cout << s[i];
				}
			}

		}
		std::cout << '\n';
	std::cin >> s;
	}
return 0;
}