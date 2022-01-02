#include <iostream>

int main() {
	long long int num, den, res;
	std::cin >> num >> den;
	while (num >= den) {
		res = 1;
		for (int i = den + 1; i <= num; ++i) {
			res *= i;
		}
		std::cout << res << '\n';
	std::cin >> num >> den;
	}
return 0;
}