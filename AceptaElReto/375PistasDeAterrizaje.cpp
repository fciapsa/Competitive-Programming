#include <iostream>
#include <string>

int main() {
	int num;
	std::string s;
	std::cin >> num;
	getline(std::cin, s);
	while (std::cin) {
		if (num <= 18) std::cout << 18 + num;
		else {
			if (num - 18 < 10) std::cout << '0';
			std::cout << num - 18;
		}
		if (s.size() > 0) {
			if (s[0] == 'C')std::cout << 'C';
			else if (s[0] == 'R') std::cout << 'L';
			else std::cout << 'R';
		}
		std::cout << '\n';
	std::cin >> num;
	getline(std::cin, s);
	}
return 0;
}