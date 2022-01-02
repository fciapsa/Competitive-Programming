#include <iostream>

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

bool resuelve() {
	int a, b, c;
	std::cin >> a >> b >> c;

	if (a == 0 && b == 0 && c == 0) return false;

	if (a != 0 && b != 0 && c != 0) std::cout << (a + b + c) / gcd(gcd(a, b), c) << '\n';
	else if (a != 0 && b != 0) std::cout << (a + b) / gcd(a, b) << '\n';
	else if (b != 0 && c != 0) std::cout << (b + c) / gcd(b, c) << '\n';
	else if (a != 0 && c != 0) std::cout << (a + c) / gcd(a, c) << '\n';
	else std::cout << "1\n";

return true;
}

int main() {
	while (resuelve());
return 0;
}