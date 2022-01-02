#include <iostream>
#include <string>

int main() {
	int T;
	std::string s;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> s;
		bool voc[5] = { false };
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'a') voc[0] = true;
			else if (s[i] == 'e') voc[1] = true;
			else if (s[i] == 'i') voc[2] = true;
			else if (s[i] == 'o') voc[3] = true;
			else if (s[i] == 'u') voc[4] = true;
		}

		if (voc[0] && voc[1] && voc[2] && voc[3] && voc[4])std::cout << "SI\n";
		else std::cout << "NO\n";
	}
return 0;
}