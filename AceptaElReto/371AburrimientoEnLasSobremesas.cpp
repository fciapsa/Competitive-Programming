#include <iostream>

int main() {
	int N;
	std::cin >> N;
	while (N != 0) {
		std::cout << (N * (3 + 3 * N)) / 2 << '\n';
	std::cin >> N;
	}
return 0;
}