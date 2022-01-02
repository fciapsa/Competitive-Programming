#include <iostream>

int main() {
	int T, a, b;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> a >> b;
		if (a < b) std::cout << "<\n";
		else if (a > b) std::cout << ">\n";
		else std::cout << "=\n";
	}
return 0;
}