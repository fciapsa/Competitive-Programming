#include <iostream>
#include <vector>

std::vector<long long int> tam(62);

char letra(long long int n, long long int k) {
	if (k <= tam[n - 1]) return letra(n - 1, k);
	else if (k <= tam[n - 1] + n + 2) {
		k -= tam[n - 1];
		if (k == 1) return 'B';
		else if (k == n + 2) return 'H';
		else return 'U';
	}
	else return letra(n - 1, k - tam[n - 1] - n - 2);
}

int main() {
	tam[0] = 0;
	for (int i = 1; i < 62; ++i) tam[i] = 2 * tam[i - 1] + i + 2;

	long long int n, k;
	std::cin >> n >> k;
	while (std::cin) {
		std::cout << letra(n, k) << '\n';
	std::cin >> n >> k;
	}
return 0;
}