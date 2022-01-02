#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> dp(1000001);
	//casos base
	/*dp[1] = 0;
	dp[2] = 0;
	dp[3] = 0;
	dp[4] = 0;*/
	for (int i = 5; i < 1000001; ++i) {
		if (i % 2 == 0) dp[i] = 3 + std::max(0,dp[i / 2]-2) + std::max(0,dp[i / 2 + 1]-2);
		else dp[i] = 3 + 2 * std::max(0,dp[i / 2 + 1]-2);
	}

	int n;
	std::cin >> n;
	while (n != 0) {
		if (n == 1 || n == 2)std::cout << "1\n";
		else if (n == 3 || n == 4) std::cout << "2\n";
		else std::cout << dp[n] << '\n';
	std::cin >> n;
	}
return 0;
}