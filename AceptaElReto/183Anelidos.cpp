#include <iostream>
#include <string>

bool resuelve() {
	int n;
	std::string s;

	std::cin >> n >> s;

	if (s.size() == 1) return false;

	s.pop_back();
	std::string aux;
	for (int i = 0; i < n; ++i) {
		aux = "";
		for (int j = 0; j < s.size(); ++j) {
			aux += s[j];
			if (s[j] == 'A') aux += 'N';
			else aux += 'A';
		}
		s = aux;
	}

	std::cout << s << "C\n";

return true;
}

int main() {
	while (resuelve());
return 0;
}