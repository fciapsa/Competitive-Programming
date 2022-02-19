#include <iostream>
#include <algorithm>

int main() {
	long long int n, k;
	std::cin >> n >> k;
	if (n == k || n == 0) std::cout << "0\n";
	else {
		if (n > k) {
			if (n % k == 0) std::cout << "0\n";
			else std::cout << std::min(k - n % k,n%k) << '\n';
		}
		else std::cout << std::min(k - n, n) << '\n';
	}

return 0;
}