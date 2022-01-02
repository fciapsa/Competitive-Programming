#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	int N, X, Y, aux;
	std::cin >> N >> X >> Y;

	std::vector<int> v(N);
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			int aux = std::min(j - i, std::abs(i - X) + 1 + std::abs(Y - j));
			++v[aux];
		}
	}
	for (int i = 1; i < N; ++i) std::cout << v[i] << '\n';
	
return 0;
}