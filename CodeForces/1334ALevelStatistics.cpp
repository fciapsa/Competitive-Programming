#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
	int T, n;
	bool ok;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n;
		ok = true;
		std::vector<int> p(n), c(n);
		for (int i = 0; i < n; ++i) std::cin >> p[i] >> c[i];

		if (c[0] > p[0]) ok = false;
		for (int i = 1; i < n && ok; ++i) {
			if (p[i] < p[i - 1] || c[i] < c[i - 1] || (c[i] -c[i-1]) > p[i]-p[i-1]) ok = false;
		}

		if (ok)std::cout << "YES\n";
		else std::cout << "NO\n";
	}
return 0;
}