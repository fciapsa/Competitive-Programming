#include <iostream>

int main() {
	int N, M;
	std::cin >> N >> M;
	if (N >= 2 && M >= 2) std::cout << N * (N - 1) / 2 + M * (M - 1) / 2 << '\n';
	else if (N >= 2) std::cout << N * (N - 1) / 2 << '\n';
	else if (M >= 2) std::cout << M * (M - 1) / 2 << '\n';
	else std::cout << "0\n";
return 0;
}