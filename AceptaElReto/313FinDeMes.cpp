#include <iostream>

int main() {
	int nc;
	std::cin >> nc;
	for (int i = 0; i < nc; ++i) {
		int s, c;
		std::cin >> s >> c;
		if (s + c >= 0) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
return 0;
}