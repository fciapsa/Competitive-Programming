#include <iostream>

int main() {
	long long int f, b;
	std::cin >> f >> b;
	while (b != 0) {
		std::cout << (f * (f + 1) - (f-b+1) * (f-b + 2)) / 2 << '\n';
	std::cin >> f >> b;
	}
return 0;
}