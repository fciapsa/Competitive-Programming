#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) std::cin >> v[i];

		bool b = true;
		for (int i = 1; i < n && b; ++i) b = v[i] > v[i - 1];

		if (b) std::cout << "SI\n";
		else std::cout << "NO\n";

		std::cin >> n;
	}

return 0;
}