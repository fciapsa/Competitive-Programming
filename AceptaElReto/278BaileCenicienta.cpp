#include <iostream>
#include <iomanip>
#include <fstream>

void resolver(int DD, int HH, int MM, int SS) {
	int hh = 0, mm = 0, ss = 0; char p = ':';
	int timetotal = 86400 * DD + 3600 * HH + 60 * MM + SS;
	int tasktime = 0;

	std::cin >> hh >> p >> mm >> p >> ss;
	while (hh != 00 || mm != 00 || ss != 00) {
		tasktime += 3600 * hh + 60 * mm + ss;
		std::cin >> hh >> p >> mm >> p >> ss;
	}
	if (tasktime < timetotal) {
		std::cout << "SI\n";
	}
	else std::cout << "NO\n";
}



int main() {
	int numCasos = 0; char p = ':', j = '\n';
	int DD = 0, HH = 0, MM = 0, SS = 0;

	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		std::cin >> DD >> p >> HH >> p >> MM >> p >> SS;
		std::cin.get(j);
		resolver(DD, HH, MM, SS);
	}
system("PAUSE");
return 0;
}