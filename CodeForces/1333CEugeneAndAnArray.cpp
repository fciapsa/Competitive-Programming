#include <iostream>
#include <vector>
#include <map>

int main() {
	long long int n, ans = 0;
	std::cin >> n;
	std::vector<long long int> v(n), sum(n + 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
		sum[i + 1] = v[i] + sum[i];
	}

	std::map<long long int, int> map;//anti-hash test cases
	for (int i = 0, j = 0; i <= n; ++i) {
		++map[sum[i]];
		while (map[sum[i]] > 1) {
			--map[sum[j]]; 
			++j;
		}
		ans += i - j;
	}

	std::cout << ans << '\n';
return 0;
}