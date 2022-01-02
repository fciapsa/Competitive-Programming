#include <iostream>
#include <vector>

const int MOD = 1000000007;
int n, x, y;

int dp(int n, std::vector<int>& memo) {
	if (memo[n] != -1) return memo[n];

	if (n == 0) {
		memo[0] = x;
		return x;
	}
	if (n == 1) {
		memo[1] = y;
		return y;
	}

	int x1, x2;
	if (memo[n - 2] == -1) x1 = dp(n - 2, memo);
	else x1 = memo[n - 2];
	if (memo[n - 1] == -1) x2 = dp(n - 1, memo);
	else x2 = memo[n - 1];

	memo[n] = (x1 + x2)%MOD;
return memo[n];
}

int main() {
	std::cin >> n >> x >> y;
	while (std::cin) {
		std::vector<int> memo(n + 1, -1);
		std::cout << dp(n, memo) << '\n';
 	std::cin >> n >> x >> y;
	}
return 0;
}