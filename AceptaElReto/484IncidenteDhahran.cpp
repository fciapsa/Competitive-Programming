#include <iostream>
#include <string>

bool resuelve() {
	std::string s;
	std::cin >> s;

	if (!std::cin) return false;

	bool punto = false;
	for (int i = 0; i < s.size() && !punto; ++i) {
		if (s[i] == '.') punto = true;
	}

	int start = 0;
	while (start < s.size() && s[start] == '0') {
		++start;
	}

	if (start == s.size()) std::cout << "0\n";
	else if (s[start] == '.') {
		++start;
			int fin = s.size() - 1;
			while (fin >= start && s[fin] == '0') {
				--fin;
			}
			if (fin < start) std::cout << "0\n";
			else {
				std::cout << "0.";
				for (int i = start; i <= fin; ++i) {
					std::cout << s[i];
				}
				std::cout << '\n';
			}
	}
	else {
		if (punto) {
			int fin = s.size() - 1;
			while (fin >= start && s[fin] == '0') {
				--fin;
			}
			if (s[fin] == '.') --fin;

			for (int i = start; i <= fin; ++i) {
				std::cout << s[i];
			}
			std::cout << '\n';
		}
		else {
			for (int i = start; i < s.size(); ++i) {
				std::cout << s[i];
			}
			std::cout << '\n';
		}
	}

	return true;
}

int main() {
	while (resuelve());
return 0;
}