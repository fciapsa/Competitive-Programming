#include <iostream>
#include <vector>

const long long int MOD = 1000000007;

int main() {
	int n, k;
	std::cin >> n;
	while (n != 0) {
		std::cin >> k;
		std::vector<int> saltos(k);
		for (int i = 0; i < k; ++i) std::cin >> saltos[i];

			std::vector<long long int> maneras(n);
			for (int i = n -1; i >= 0; --i) {
				for (int j = 0; j < saltos.size(); ++j) {
					if (i + saltos[j] == n) ++maneras[i];
					else if (i + saltos[j] < n) {
						maneras[i] += maneras[i + saltos[j]];
						maneras[i] %= MOD;
					}
				}
			}

		std::cout << maneras[0] << '\n';
	std::cin >> n;
	}
return 0;
}