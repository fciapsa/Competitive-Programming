#include <iostream>
#include <string>

int main() {
	int T;
	std::string s1, s2;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> s1 >> s2;
		if (s1 == "Luke" && s2 == "padre") std::cout << "TOP SECRET\n";
		else std::cout << s1 << ", yo soy tu " << s2 << '\n';
	}
return 0;
}