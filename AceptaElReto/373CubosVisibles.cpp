#include <iostream>

int main() {
	int t;
	long long int n;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n;
		std::cout << n*6*(n-2) + 8 << '\n';
	}
return 0;
}