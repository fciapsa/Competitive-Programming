#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;
	while (s != "FIN") {
		bool keep = true;
		for (int i = s.size() - 1; i >= 0 && keep; --i) {
			if (s[i] == 'F') s[i] = '0';
			else {
				keep = false;
				switch (s[i]) {
				case '0': s[i] = '1'; break;
				case '1': s[i] = '2'; break;
				case '2': s[i] = '3'; break;
				case '3': s[i] = '4'; break;
				case '4': s[i] = '5'; break;
				case '5': s[i] = '6'; break;
				case '6': s[i] = '7'; break;
				case '7': s[i] = '8'; break;
				case '8': s[i] = '9'; break;
				case '9': s[i] = 'A'; break;
				case 'A': s[i] = 'B'; break;
				case 'B': s[i] = 'C'; break;
				case 'C': s[i] = 'D'; break;
				case 'D': s[i] = 'E'; break;
				case 'E': s[i] = 'F'; break;
				}
			}
		}
		if (keep) std::cout << '1';
		std::cout << s << '\n';

	std::cin >> s;
	}
return 0;
}