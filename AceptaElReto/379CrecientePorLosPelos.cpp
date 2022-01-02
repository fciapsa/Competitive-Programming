#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)std::cin >> v[i];

		if (v[n - 1] != v[0] + n - 1) {//tiene siguiente
			int i = n - 1;
			while (v[i] != v[i - 1]) --i;
			++v[i];
			for (int j = i + 1; j < n; ++j) v[j] = v[i];
		}
		else {
			++v[0];
			for (int i = 1; i < n; ++i)v[i] = v[0];
		}
		std::cout << v[0];
		for (int i = 1; i < n; ++i)std::cout << ' ' << v[i];
		std::cout << '\n';
	std::cin >> n;
	}
return 0;
}