#include <iostream>
#include <string>

int main() {
	std::string s;
	while (getline(std::cin, s)) std::cout << s << '\n';
return 0;
}