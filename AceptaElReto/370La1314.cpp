#include <iostream>

int main() {
	int a, b, T;
	char aux;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> a >> aux >> b;
		if (a == b) std::cout << "NO\n";
		else {
			if (a < b && a % 2 == 0 && a + 1 == b) std::cout << "SI\n";
			else if (b < a && b % 2 == 0 && b + 1 == a) std::cout << "SI\n";
			else std::cout << "NO\n";
		}
	}
return 0;
}