#include <iostream>
#include <string>

int main() {
	int k = 1;
	std::string s;
	std::cin >> s;
	while (s != "*") {
		std::cout << "Case " << k << ": ";
		if (s[0] == 'H') std::cout << "Hajj-e-Akbar\n";
		else std::cout << "Hajj-e-Asghar\n";
	++k;
	std::cin >> s;
	}
return 0;
}