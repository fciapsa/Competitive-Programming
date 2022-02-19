#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;
	bool ok = true;
	int hasta = s.size() / 2, hasta2, hasta3;
	for (int i = 0; i < hasta && ok; ++i) {
		ok = s[i] == s[s.size()-i-1];
	}
	hasta2 = hasta/2;
	for (int i = 0; i < hasta2 && ok; ++i) {
		ok = s[i] == s[hasta - i- 1];
	}
	hasta3 = hasta + hasta2;
	for (int i = hasta + 1, j = 1; i < hasta3 && ok; ++i, ++j) {
		ok = s[i] == s[s.size() - j];
	}
	if (ok)std::cout << "Yes\n";
	else std::cout << "No\n";

return 0;
}