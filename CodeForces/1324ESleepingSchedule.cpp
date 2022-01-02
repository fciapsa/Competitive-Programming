#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, h, l, r;
	std::cin >> n >> h >> l >> r;
	std::vector<int> wait(n);
	for (int i = 0; i < n; ++i) std::cin >> wait[i];

	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(h));
	
	int aux1, aux2, sleep1, sleep2;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < h; ++j) {
			sleep1 = (j + wait[i]) % h;
			if (sleep1 >= l && sleep1 <= r) aux1 = 1 + dp[i + 1][sleep1];
			else aux1 = dp[i + 1][sleep1];

			sleep2 = (j + wait[i] - 1) % h;
			if (sleep2 >= l && sleep2 <= r) aux2 = 1 + dp[i + 1][sleep2];
			else aux2 = dp[i + 1][sleep2];

			dp[i][j] = std::max(aux1, aux2);
		}
	}

	std::cout << dp[0][0] << '\n';
return 0;
}