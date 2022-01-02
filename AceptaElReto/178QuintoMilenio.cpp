#include <iostream>
#include <string>
#include <cctype>

int main() {
	int T, i, j, tam1, tam2;
	std::string s1, s2;
	std::cin >> T;
	std::cin.ignore();
	for (int t = 0; t < T; ++t) {
		getline(std::cin, s1);
		getline(std::cin, s2);
		tam1 = s1.size();
		tam2 = s2.size();
		i = 0;
		j = 0;
		while (i < tam1 && j < tam2) {
			while (s1[i] == ' ') ++i;
			while (s2[j] == ' ') ++j;

			if (isupper(s1[i])) s1[i] = char(tolower(s1[i]));
			if (isupper(s2[j])) s2[j] = char(tolower(s2[j]));

			while (i < tam1 && s1[i] != s2[j]) {
				++i;
				if(i < tam1 && isupper(s1[i])) s1[i] = char(tolower(s1[i]));
			}
			if (i < tam1) {
				++i;
				++j;
			}
		}

		if (j == tam2) std::cout << "SI\n";
		else std::cout << "NO\n";
	}
return 0;
}