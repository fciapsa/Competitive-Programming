#include <iostream>
#include <string>

bool resuelve() {
	std::string n;
	std::cin >> n;

	if (!std::cin) return false;

	std::cout << n[0];
	for (int i = 1; i < n.size(); ++i) {
		std::cout << '0' << n[i];
	}
	std::cout << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}