#include <iostream>
#include <vector>
#include <string>

const char FIN = '5';

int main() {
	int F, C, x, y, i;
	std::string s;
	std::cin >> F >> C;
	while (F != 0) {
		std::cin >> x >> y;
		std::cin.ignore();
		getline(std::cin, s);
		F *= 2;
		C *= 2;
		std::vector<std::vector<char>> patron(F, std::vector<char>(C,' '));
		for (int i = 1; i < F; i += 2) {
			for (int j = 1; j < C; j += 2) {
				patron[i][j] = '.';
			}
		}
		x += (x - 1);
		y += (y - 1);
		patron[x][y] = 'O';
		
		i = 0;
		while (s[i] != FIN) {
			switch (s[i]) {
			case '1': 
				--x;
				--y;
				if (patron[x][y] != 'X' && patron[x][y] != '\\') {
					if (patron[x][y] == '/') patron[x][y] = 'X';
					else patron[x][y] = '\\';
			    }
				--x;
				--y;
				patron[x][y] = 'O'; break;
			case '2':
				--x;
				patron[x][y] = '|';
				--x;
				patron[x][y] = 'O'; break;
			case '3':
				--x;
				++y;
				if (patron[x][y] != 'X' && patron[x][y] != '/') {
					if (patron[x][y] == '\\') patron[x][y] = 'X';
					else patron[x][y] = '/';
				}
				--x;
				++y;
				patron[x][y] = 'O'; break;
			case '4':
				--y;
				patron[x][y] = '-';
				--y;
				patron[x][y] = 'O'; break;
			case '6':
				++y;
				patron[x][y] = '-';
				++y;
				patron[x][y] = 'O'; break;
			case '7':
				++x;
				--y;
				if (patron[x][y] != 'X' && patron[x][y] != '/') {
					if (patron[x][y] == '\\') patron[x][y] = 'X';
					else patron[x][y] = '/';
				}
				++x;
				--y;
				patron[x][y] = 'O'; break;
			case '8':
				++x;
				patron[x][y] = '|';
				++x;
				patron[x][y] = 'O'; break;
			case '9':
				++x;
				++y;
				if (patron[x][y] != 'X' && patron[x][y] != '\\') {
					if (patron[x][y] == '/') patron[x][y] = 'X';
					else patron[x][y] = '\\';
				}
				++x;
				++y;
				patron[x][y] = 'O'; break;
			}
		++i;
		}
		std::cout << '+';
		for (int i = 0; i < C-1; ++i) std::cout << '-';
		std::cout << "+\n";
		for (int i = 1; i < F; ++i) {
			std::cout << '|';
			for (int j = 1; j < C; ++j) {
				std::cout << patron[i][j];
			}
			std::cout << "|\n";
		}
		std::cout << '+';
		for (int i = 0; i < C-1; ++i) std::cout << '-';
		std::cout << "+\n";
	std::cin >> F >> C;
	}
return 0;
}