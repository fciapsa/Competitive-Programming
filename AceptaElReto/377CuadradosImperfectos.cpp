#include <iostream>
#include <string>

int main() {
	std::string s, sol;
	int x, pot;
	std::cin >> s;
	while (std::cin) {
		pot = 1;
		x = 0;
		for (int i = s.size() - 1, j = 0; i >= 0 && j < 4; --i, ++j) {
			x += (s[i] - '0') * pot;
			pot *= 10;
		}
		sol = "";
		for (int i = 0; i < 4; ++i) {
			if (x % 2 == 0) sol = '0' + sol;
			else sol = '1' + sol;
			x /= 2;
		}
		if (sol == "0000" || sol == "0001" || sol == "0100" || sol == "1001")std::cout << "NO SE\n";
		else std::cout << "IMPERFECTO\n";
	std::cin >> s;
	}
return 0;
}