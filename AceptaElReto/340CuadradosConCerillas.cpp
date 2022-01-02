#include <iostream>

int main() {
	int T, N, M;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> N >> M;
		std::cout << 4 + (N + M - 2) * 3 + (N - 1) * (M - 1) * 2 << '\n';
	}
return 0;
}