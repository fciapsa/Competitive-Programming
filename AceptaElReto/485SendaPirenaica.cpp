#include <iostream>
#include <vector>

bool resuelve() {
	int num;
	std::cin >> num;

	if (num == 0) return false;

	std::vector<int> v(num);
	int tot = 0;
	for (int i = 0; i < num; ++i) {
		std::cin >> v[i];
		tot += v[i];
	}

	std::cout << tot;
	int acum = v[0];
	for (int i = 1; i < num; ++i) {
		std::cout << ' ' << tot - acum;
		acum += v[i];
	}
	std::cout << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}