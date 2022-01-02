#include <iostream>
#include <string>
#include <vector>

bool resuelve(){
	std::string s;
	std::cin >> s;

	if (!std::cin) return false;

	std::vector<int> v(10, 0);
	for (int i = 0; i < s.size(); ++i) {
		++v[int(s[i]) - int('0')];
	}

	bool b = true;
	for (int i = 1; i < v.size() && b; ++i) {
		b = v[i] == v[i - 1];
	}

	if (b) std::cout << "subnormal\n";
	else std::cout << "no subnormal\n";

	return true;
}

int main() {
	while (resuelve());

	return 0;
}