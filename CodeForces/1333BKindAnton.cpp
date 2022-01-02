#include <iostream>
#include <vector>

int main() {
	int T, n;
	bool plus, minus, ok;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> n;
		std::vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		for (int i = 0; i < n; ++i) std::cin >> b[i];

		ok = true;
		plus = false;
		minus = false;
		if (a[0] != b[0]) ok = false;
		if (a[0] > 0) plus = true;
		else if (a[0] < 0) minus = true;
		for (int i = 1; i < n && ok; ++i) {
			if (a[i] != b[i]) {
				if (b[i] > a[i]) {
					if (!plus) ok = false;
				}
				else if (b[i] < a[i]) {
					if (!minus) ok = false;
				}
			}
			if (a[i] < 0) minus = true;
			else if (a[i] > 0) plus = true;
		}

		if (ok) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
return 0;
}