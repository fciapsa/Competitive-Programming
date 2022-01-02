#include <iostream>
#include <string>

int main() {
	int T;
	std::string s;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> s;
		if (s.length() == 3) {
			if ((s[0] == 'o' && s[1] == 'n') || (s[0] == 'o' && s[2] == 'e') || (s[1] == 'n' && s[2] == 'e')) {
				std::cout << "1\n";
			}
			else std::cout << "2\n";
		}
		else std::cout << "3\n";
	}
return 0;
}