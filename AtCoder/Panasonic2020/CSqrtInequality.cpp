#include <iostream>

int main() {
	unsigned long long int a, b, c;
	std::cin >> a >> b >> c;
	if (a + b > c) std::cout << "No\n";
	else {
		if (4 * a * b < (c - a - b) * (c - a - b)) std::cout << "Yes\n";
		else std::cout << "No\n";
	}
return 0;
}