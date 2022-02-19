#include <iostream>

int main() {
	char a, b, c;
	std::cin >> a >> b >> c;
	if (a == 'A' && b == 'A' && c == 'A') std::cout << "No\n";
	else if (a == 'B' && b == 'B' && c == 'B') std::cout << "No\n";
	else std::cout << "Yes\n";
return 0;
}