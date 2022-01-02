#include <iostream>
#include <string>

int main() {
	bool b;
	int T, last;
	std::string s;

	std::cin >> T;
	std::cin.ignore();
	for (int t = 0; t < T; ++t) {
		getline(std::cin, s);
		b = s.size() >= 3 && s[0] == 'M' && s[1] == 'A' && s[2] == 'C';

		last = s.size() - 1;
		if (s[last] == 'A') {
			if (b) std::cout << "MULATO\n";
			else std::cout << "INDIO\n";
		}
		else if (s.size() >= 2) {
			if (s[last - 1] == 'I' && s[last] == 'X') {
				if (b) std::cout << "MULATO\n";
				else std::cout << "GALO\n";
			}
			else if (s[last - 1] == 'U' && (s[last] == 'S' || s[last] == 'M')) {
				if (b) std::cout << "MULATO\n";
				else std::cout << "ROMANO\n";
			}
			else if (s[last - 1] == 'I' && s[last] == 'C') {
				if (b) std::cout << "MULATO\n";
				else std::cout << "GODO\n";
			}
			else if (s[last - 1] == 'A' && s[last] == 'S') {
				if (b) std::cout << "MULATO\n";
				else std::cout << "GRIEGO\n";
			}
			else if (s[last - 1] == 'A' && s[last] == 'F') {
				if (b) std::cout << "MULATO\n";
				else std::cout << "NORMANDO\n";
			}
			else if (((s[last - 1] == 'I' || s[last - 1] == 'O') && s[last] == 'S') || (s[last - 1] == 'A' && s[last] == 'X')) {
				if (b) std::cout << "MULATO\n";
				else std::cout << "BRETON\n";
			}
			else if (s[last - 1] == 'E' && s[last] == 'Z') {
				if (b) std::cout << "MULATO\n";
				else std::cout << "HISPANO\n";
			}
			else if (b) std::cout << "PICTO\n";
			else std::cout << "PLUS ULTRA\n";
		}
		else std::cout << "PLUS ULTRA\n";
	}


return 0;
}