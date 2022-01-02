#include <iostream>
#include <string>

int main() {
	bool r, l;
	std::string s;
	int n;
	std::cin >> n;
	while (n != 0) {
		std::cin >> s;
		r = false; l = false;
		for (int i = 0; i < n && (!r || !l); ++i) {
			if (s[i] == 'D') r = true;
			else if (s[i] == 'I') l = true;
		}
		if (r && l) std::cout << "ALGUNO NO COME\n";
		else std::cout << "TODOS COMEN\n";
	std::cin >> n;
	}
return 0;
}