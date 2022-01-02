#include <iostream>
#include <vector>

int main() {
	int n, max;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	std::cin >> a[0];
	b[0] = a[0];
	max = a[0];
	for (int i = 1; i < n; ++i) {
		std::cin >> b[i];
		if (b[i] > 0) {//new max
			max = max + b[i];
			a[i] = max;
		}
		else a[i] = b[i] + max;
	}
	std::cout << a[0];
	for (int i = 1; i < n; ++i) std::cout << ' ' << a[i];
	std::cout << '\n';
return 0;
}