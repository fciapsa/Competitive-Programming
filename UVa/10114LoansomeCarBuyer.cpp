#include <iostream>
#include <vector>

struct pair {
	int month;
	double perc;
};

int main() {
	int duration, d, month;
	double down, owed, worth, everyMonth;
	std::cin >> duration >> down >> owed >> d;
	while (duration > 0) {
		std::vector<pair> deprecs(d);
		for (int i = 0; i < d; ++i) std::cin >> deprecs[i].month >> deprecs[i].perc;

		everyMonth = owed / duration;
		worth = (owed + down) * (1 - deprecs[0].perc);
		d = 0;
		month = 0;
		while (owed >= worth) {
			++month;
			if (d + 1 < deprecs.size() && deprecs[d + 1].month == month) ++d;

			owed -= everyMonth;
			worth = worth * (1 - deprecs[d].perc);
		}

		if (month == 1) std::cout << "1 month\n";
		else std::cout << month << " months\n";

	std::cin >> duration >> down >> owed >> d;
	}
return 0;
}