#include <iostream>

int main() {
	int x;
	std::cin >> x;
	long long int sol = 0;
	sol += (x / 500) * 1000;
	x %= 500;
	sol += (x / 5) * 5;
	std::cout << sol << '\n';
return 0;
}