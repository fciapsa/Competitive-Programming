#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	int t, n, groups;
	bool repeat;
	std::cin >> t;
	for (int m = 0; m < t; ++m) {
		std::cin >> n;
		groups = 1;
		repeat = false;
		std::vector<int> v(n);
		std::cin >> v[0];
		for (int i = 1; i < n; ++i) {
			std::cin >> v[i];
			if (v[i] != v[i - 1]) ++groups;
			else repeat = true;
		}
		
		if (v[n - 1] == v[0]) repeat = true;
		
		if (groups == 1) {
			std::cout << "1\n";
			std::cout << '1';
			for (int i = 1; i < n; ++i) std::cout << " 1";
			std::cout << '\n';
		}
		else if (groups % 2 == 0) {
			std::cout << "2\n";
			std::cout << '1';
			int c = 1;
			for (int i = 1; i < n; ++i) {
				if (v[i] == v[i - 1]) std::cout << ' ' << c;
				else {
					if (c == 1) c = 2;
					else c = 1;
					std::cout << ' ' << c;
				}
			}
			std::cout << '\n';
		}
		else if (repeat) {
			std::cout << "2\n";
			std::cout << '1';
			int c = 1;
			for (int i = 1; i < n; ++i) {
				if (v[i] != v[i - 1]) {
					if (c == 1) c = 2;
					else c = 1;
					std::cout << ' ' << c;
				}
				else if (repeat) {
					repeat = false;
					if (c == 1) c = 2;
					else c = 1;
					std::cout << ' ' << c;
				}
				else std::cout << ' ' << c;
			}
			std::cout << '\n';
		}
		else {
			std::cout << "3\n";
			std::cout << '1';
			int c = 1;
			--n;
			for (int i = 1; i < n; ++i) {
				if (v[i] == v[i - 1]) std::cout << ' ' << c;
				else {
					if (c == 1) c = 2;
					else c = 1;
					std::cout << ' ' << c;
				}
			}
			std::cout << " 3\n";
		}
	}
return 0;
}