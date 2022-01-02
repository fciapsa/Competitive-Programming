#include <iostream>
#include <vector>

const std::vector<int> v = { 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51 };

int main() {
	int K;
	std::cin >> K;
	std::cout << v[K - 1] << '\n';
return 0;
}