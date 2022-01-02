#include <iostream>

int main() {
	int nc;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		int n;
		std::cin >> n;
		if (n % 3 == 1)std::cout << "NO\n";
		else std::cout << "SI\n";
	}
return 0;
}