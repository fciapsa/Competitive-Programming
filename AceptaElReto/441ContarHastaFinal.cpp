#include <iostream>
#include <string>

bool resuelve() {
	std::string s;
	std::cin >> s;

	if (!std::cin) return false;

	int i = s.size() - 1;
	while (i > -1 && (s[i] == '9' || s[i] == '.')) {
		if (s[i] == '9') s[i] = '0';
		--i;
	}

	if(i > -1) ++s[i];

	if (s[0] == '0') {
		int c = 0, j = 0;
		while (j < s.size() && s[j] != '.') {
			++c;
			++j;
		}
		if (c == 3) std::cout << "1.";
		else std::cout << '1';
	}
	std::cout << s << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}