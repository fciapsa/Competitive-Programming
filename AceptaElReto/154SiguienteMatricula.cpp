#include <iostream>
#include <string>

const std::string fin = "9999 ZZZ";

int main() {
	std::string m;
	getline(std::cin, m);
	while (m != fin) {
		if (m[3] == '9') {
			m[3] = '0';
			if (m[2] == '9') {
				m[2] = '0';
				if (m[1] == '9') {
					m[1] = '0';
					if (m[0] == '9') {
						m[0] = '0';
						if (m[7] == 'Z') {
							m[7] = 'B';
							if (m[6] == 'Z') {
								m[6] = 'B';
								++m[5];
								if (m[5] == 'A' || m[5] == 'E' || m[5] == 'I' || m[5] == 'O' || m[5] == 'U') ++m[5];
							}
							else {
								++m[6];
								if (m[6] == 'A' || m[6] == 'E' || m[6] == 'I' || m[6] == 'O' || m[6] == 'U') ++m[6];
							}
						}
						else {
							++m[7];
							if (m[7] == 'A' || m[7] == 'E' || m[7] == 'I' || m[7] == 'O' || m[7] == 'U') ++m[7];
						}
					}
					else ++m[0];
				}
				else ++m[1];
			}
			else ++m[2];
		}
		else ++m[3];

		std::cout << m << '\n';
		getline(std::cin, m);
	}
	return 0;
}