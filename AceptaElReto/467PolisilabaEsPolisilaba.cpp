#include <iostream>
#include <string>
#include <cctype>

bool iguales(std::string & s1, std::string & s2) {
	if (s1.size() != s2.size()) return false;

	bool ok = true;
	for (int i = 0; i < s1.size() && ok; ++i) {
		if (isupper(s1[i])) s1[i] = tolower(s1[i]);
		if (isupper(s2[i])) s2[i] = tolower(s2[i]);

		ok = s1[i] == s2[i];
	}

return ok;
}

int main() {
	int N;
	std::cin >> N;

	std::string s1, h, s2;
	for (int i = 0; i < N; ++i) {
		std::cin >> s1 >> h >> s2;
		if (iguales(s1, s2)) std::cout << "TAUTOLOGIA\n";
		else std::cout << "NO TAUTOLOGIA\n";
	}

return 0;
}