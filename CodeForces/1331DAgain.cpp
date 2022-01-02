#include <iostream>

int main() {
	char c;
	int x;
	std::cin >> c >> x;
	if (x % 2 == 0) std::cout << "0\n";
	else std::cout << "1\n";
}