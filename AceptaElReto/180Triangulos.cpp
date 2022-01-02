#include <iostream>
#include <iomanip>
#include <fstream>


int main() {
	int numCasos = 0, t1 = 0, t2 = 0, t3 = 0;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		std::cin >> t1 >> t2 >> t3;
		int t1c = t1*t1; int t2c = t2*t2; int t3c = t3*t3;
		if (t1 >= t2 + t3 || t2 >= t1 + t3 || t3 >= t1 + t2) {
			std::cout << "IMPOSIBLE" << '\n';
		}
		else if (t1c + t2c == t3c || t2c + t3c == t1c || t1c + t3c == t2c) {
			std::cout << "RECTANGULO" << '\n';
		}
		else if (t1*t1 + t2*t2 < t3*t3 || t2*t2 + t3*t3 < t1*t1 || t1*t1 + t3*t3 < t2*t2) {
			std::cout << "OBTUSANGULO" << '\n';
		}
		else std::cout << "ACUTANGULO" << '\n';
	}
	system("PAUSE");
	return 0;
}