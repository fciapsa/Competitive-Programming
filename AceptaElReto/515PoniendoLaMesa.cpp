#include <iostream>

int main() {
	int N;
	std::cin >> N;
	while (N != 0) {
		if (N == 1 || N % 2 == 0) std::cout << N << '\n';
		else std::cout << N - 1 << '\n';
		std::cin >> N;
	}
	return 0;
}