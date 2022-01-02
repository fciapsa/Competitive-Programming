#include <iostream>
#include <string>

int main() {
	int T, tot = 0, x;
	std::string s;
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		if (s[0] == 'd') {
			std::cin >> x;
			tot += x;
		}
		else std::cout << tot << '\n';
	}
return 0;
}