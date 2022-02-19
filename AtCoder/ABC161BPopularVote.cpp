#include <iostream>
#include <vector>

int main() {
	double n, m, tot = 0, cont = 0;
	std::cin >> n >> m;
	std::vector<double> v(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
		tot += v[i];
	}

	tot = (tot / (4 * m));
	for (int i = 0; i < n; ++i) {
		if (v[i] < tot) continue;
		++cont;
	}

	if (cont >= m) std::cout << "Yes\n";
	else std::cout << "No\n";

return 0;
}