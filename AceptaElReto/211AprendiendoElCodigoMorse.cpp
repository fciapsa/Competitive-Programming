#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cctype>

const std::unordered_map<char, std::string> codigo = {
	{'A',".-"},{'B',"-..."},{'C',"-.-."},{'D',"-.."},{'E',"."},{'F',"..-."},{'G',"--."},{'H',"...."},{'I',".."},
	{'J',".---"},{'K',"-.-"},{'L',".-.."},{'M',"--"},{'N',"-."},{'O',"---"},{'P',".--."},{'Q',"--.-"},{'R',".-."},
	{'S',"..."},{'T',"-"},{'U',"..-"},{'V',"...-"},{'W',".--"},{'X',"-..-"} ,{'Y',"-.--"},{'Z',"--.."}
};

int main() {
	char first;
	std::string s, s2;
	std::cin >> s;
	while (std::cin) {
		if (isupper(s[0])) first = s[0];
		else first = char(toupper(s[0]));

		std::string s2 = "";
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == 'o' || s[i] == 'O') s2 += '-';
				else if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'u'
					|| s[i] == 'U') s2 += '.';
		    }

			if (s2 == codigo.at(first)) std::cout << s << " OK\n";
			else std::cout << s << " X\n";

	std::cin >> s;
	}
return 0;
}