#include <iostream>

int main() {
	int K, N, M, X, Y;
	std::cin >> K;
	while (K != 0) {
		std::cin >> N >> M;
		for (int k = 0; k < K; ++k) {
			std::cin >> X >> Y;
			if (X == N || Y == M) std::cout << "divisa\n";
			else if (Y > M) {
				if (X < N) std::cout << "NO\n";
				else std::cout << "NE\n";
			}
			else {
				if (X < N) std::cout << "SO\n";
				else std::cout << "SE\n";
			}
		}
	std::cin >> K;
	}
return 0;
}