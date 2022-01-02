#include <iostream>
#include <algorithm>

int main() {
	long long int N, A, B;
	std::cin >> N >> A >> B;
	long long int sol = (N / (A + B)) * A + std::min(N % (A + B), A);

	std::cout << sol << '\n';
	return 0;
}