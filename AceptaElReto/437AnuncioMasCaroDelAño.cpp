#include <iostream>
#include <string>

int main() {
	int nc;
	std::cin >> nc;

	for (int i = 0; i < nc; ++i) {
		std::string s;
		std::cin >> s;
		int hh = (int(s[0]) - int('0')) * 10 + int(s[1]) - int('0');
		int mm = (int(s[3]) - int('0')) * 10 + int(s[4]) - int('0');
		int ss = (int(s[6]) - int('0')) * 10 + int(s[7]) - int('0');

		int h, m, seg;
			if (ss > 0) {
				h = 23 - hh;
				m = 59 - mm;
				seg = 60 - ss;
			}
			else if(mm > 0) {
				h = 23 - hh;
				m = 60 - mm;
				seg = 0;
			}
			else{
				h = 24 - hh;
				m = 0;
				seg = 0;
			}

			if (h < 10) std::cout << '0';
			std::cout << std::to_string(h) << ':';

			if (m < 10) std::cout << '0';
			std::cout << std::to_string(m) << ':';

			if (seg < 10) std::cout << '0';
			std::cout << std::to_string(seg) << '\n';
		
	}

	return 0;
}