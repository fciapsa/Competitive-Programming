#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
	ll T, n, x, sum, i;
	bool ok;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n >> x;
		std::vector<ll> a(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		sort(a.rbegin(), a.rend());

		ok = true;
		i = 0;
		sum = 0;
		while (ok && i < n) {
			if ((sum + a[i]) / (i + 1) >= x) sum += a[i];
			else ok = false;
		++i;
		}
		if (!ok) --i;

		std::cout << i << '\n';
	}
return 0;
}