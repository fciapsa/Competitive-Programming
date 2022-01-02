#include <iostream>

int main() {
	double h, u, d, f, act, lose;
	int day, phase;
	std::cin >> h >> u >> d >> f;
	while (h != 0) {
		act = 0;
		day = 0;
		lose = u * (f / 100);

		phase = 0;
		while (true) {
			if (phase % 2 == 0) {//day
				++day;
				if(u>0) act += u;
				if (act > h) break;
				u -= lose;
			}
			else {
				act -= d;
				if (act < 0) break;
			}
			++phase;
		}

		if (act > h) std::cout << "success ";
		else std::cout << "failure ";
		std::cout << "on day " << day << '\n';

	std::cin >> h >> u >> d >> f;
	}
return 0;
}