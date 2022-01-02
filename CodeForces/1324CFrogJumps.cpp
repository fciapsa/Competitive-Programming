#include <iostream>
#include <string>

int main() {
	int T, act, max;
	std::string s;
	std::cin >> T;
	std::cin.ignore();
	for (int i = 0; i < T; ++i) {
		getline(std::cin, s);
		act = 1;
		max = 1;
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == 'L') ++act;
			else {
				if (act > max) max = act;
				act = 1;
			}
		}
		if (act > max) max = act;
		std::cout << max << '\n';
	}
return 0;
}