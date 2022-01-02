#include <iostream>
#include <string>


bool resuelve() {
	int x, y;
	std::cin >> x >> y;

	if (x == 0 && y == 0) return false;

	std::string s = "abcdefgh";

	std::cout << s[8-x] << y << '\n';

return true;
}

int main() {
	while (resuelve());
	return 0;
}