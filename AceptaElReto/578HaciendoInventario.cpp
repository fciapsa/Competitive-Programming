#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

int main() {
	std::string s;
	int n;
	std::cin >> n;
	while (n != 0) {
		std::cin.ignore();
		std::unordered_set<std::string> conj;
		for (int i = 0; i < n; ++i) {
			getline(std::cin, s);
			for (int j = 0; j < s.size(); ++j) {
				if (isupper(s[j])) s[j] = tolower(s[j]);
			}
			conj.insert(s);
		}
		std::cout << conj.size() << '\n';
	std::cin >> n;
	}
	return 0;
}