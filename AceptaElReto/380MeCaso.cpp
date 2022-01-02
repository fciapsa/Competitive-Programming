#include <iostream>

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		int sol = 0, aux;
		for (int i = 0; i < n; ++i) {
			std::cin >> aux;
			sol += aux;
		}
		std::cout << sol << '\n';
		std::cin >> n;
	}
return 0;
}