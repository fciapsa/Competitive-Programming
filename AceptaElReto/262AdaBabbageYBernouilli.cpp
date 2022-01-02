#include <iostream>

const int MOD = 46337;

int main() {
	int n, p, aux, ans;
	std::cin >> n >> p;
	while (n != 0) {
		ans = 1;
		for (int i = 2; i <= n; ++i) {
			aux = i;
			for (int j = 2; j <= p; ++j) {
				aux *= i;
				aux %= MOD;
			}
			ans += aux;
			ans %= MOD;
		}
		std::cout << ans << '\n';
	std::cin >> n >> p;
	}
return 0;
}