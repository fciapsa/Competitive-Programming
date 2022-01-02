#include <iostream>
#include <string>

bool esMenor(std::string const& s1, std::string const& s2) {
	int i = 0;
	while (i < s1.size() && i < s2.size()) {
		if (s1[i] == 'c' && s2[i] == 'c') {
			++i;
			if (i < s1.size() && i < s2.size() && s1[i] == 'h' && s2[i] == 'h') ++i;
			else if (i < s1.size() && s1[i] == 'h') return false;
			else if (i < s2.size() && s2[i] == 'h') return true;
		}
		else if (s1[i] == 'l' && s2[i] == 'l') {
			++i;
			if (i < s1.size() && i < s2.size() && s1[i] == 'l' && s2[i] == 'l') ++i;
			else if (i < s1.size() && s1[i] == 'l') return false;
			else if (i < s2.size() && s2[i] == 'l') return true;
		}
		else {
			if (s1[i] < s2[i]) return true;
			else if (s1[i] == s2[i]) ++i;
			else return false;
		}
	}

	return s1.size() < s2.size();
}

bool resuelve() {
	std::string s1, s2;
	std::cin >> s1 >> s2;

	if (!std::cin) return false;

	if (esMenor(s1, s2)) std::cout << s1 << '\n';
	else std::cout << s2 << '\n';

	return true;
}

int main() {
	while (resuelve());
	return 0;
}