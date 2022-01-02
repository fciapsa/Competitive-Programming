#include <iostream>
#include <string>

void base6(int n, std::string &sol) {
	if (n < 6) sol += char(n + int('0'));
	else {
		base6(n / 6, sol);
		sol += char(n % 6 + int('0'));
	}
}

int main() {
	int c, n;
	std::cin >> c;
	for (int i = 0; i < c; ++i) {
		std::cin >> n;
		std::string sol = "";
		base6(n, sol);
		for (int j = 0; j < sol.size(); ++j) {
			std::cout << sol[j];
		}
		std::cout << '\n';
	}
	return 0;
}