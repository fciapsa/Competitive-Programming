#include <iostream>
#include <vector>

const std::vector<int> diasMes = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool esBisiesto(int x) {
	if (x <= 1752) return x % 4 == 0;
	else return (x % 4 == 0 && x % 100 != 0) || x == 2000;
}

struct date {
	int day, month, year;
	bool operator<(date const& other) const {
		return year < other.year || (year == other.year && month < other.month || (year == other.year && month == other.month &&
			day < other.day));
	}
	date& operator--() {
		--this->day;
		if (this->day == 0) {
			--this->month;
			if (this->month == 0) {
				this->day = 31;
				this->month = 12;
				--this->year;
			}
			else if (this->month == 2) {
				if (esBisiesto(this->year)) this->day = 29;
				else this->day = 28;
			}
			else this->day = diasMes[this->month];
		}

		return *this;
	}
};

const date DATE1 = { 15,10,1582 }, DATE2 = { 1,3,1700 }, DATE3 = { 14,9,1752 };

int main() {
	int T;
	date x;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> x.day >> x.month >> x.year;

		if (x < DATE1) std::cout << x.day << ' ' << x.month << ' ' << x.year << '\n';
		else if (x < DATE2) {
			for (int i = 0; i < 10; ++i) --x;
			std::cout << x.day << ' ' << x.month << ' ' << x.year << '\n';
		}
		else if (x < DATE3) {
			for (int i = 0; i < 11; ++i) --x;
			std::cout << x.day << ' ' << x.month << ' ' << x.year << '\n';
		}
		else std::cout << x.day << ' ' << x.month << ' ' << x.year << '\n';
	}
	return 0;
}