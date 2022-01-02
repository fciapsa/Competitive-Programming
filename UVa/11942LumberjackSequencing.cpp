#include <iostream>
#include <vector>

int main() {
	int n;
	bool ok1, ok2;
	std::vector<int> v(10);
	std::cout << "Lumberjacks:\n";
	std::cin >> n;
	while (n--) {
		for (int i = 0; i < 10; ++i) std::cin >> v[i];
		ok1 = true;
		for (int i = 1; i < 10 && ok1; ++i) ok1 = v[i] > v[i - 1];
		ok2 = true;
		for (int i = 1; i < 10 && ok2; ++i) ok2 = v[i] < v[i - 1];

		if (ok1 || ok2) std::cout << "Ordered\n";
		else std::cout << "Unordered\n";
	}
return 0;
}