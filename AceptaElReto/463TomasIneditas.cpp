#include <iostream>
#include <vector>
#include <string>

int main() {
	int h, max_h;
	std::string s;
	getline(std::cin, s);
	while (std::cin) {
		h = 0; 
		max_h = 0;
		std::vector<std::vector<char>> mat(s.size(), std::vector<char>(s.size(),' '));
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'I') {
				if (h > max_h) max_h = h;
				mat[i][h] = '_';
			}
			else if (s[i] == 'S') {
				if (h > max_h) max_h = h;
				mat[i][h] = '/';
				++h;
			}
			else {
				--h;
				mat[i][h] = '\\';
			}
		}

		for (int i = 0; i < s.size(); ++i) std::cout << '#';
		std::cout << "##\n";
		for (int j = max_h; j >= 0; --j) {
			std::cout << '#';
			for (int i = 0; i < s.size(); ++i) {
				std::cout << mat[i][j];
			}
			std::cout << "#\n";
		}
		for (int i = 0; i < s.size(); ++i) std::cout << '#';
		std::cout << "##\n";

	getline(std::cin, s);
	}
return 0;
}