#include <iostream>

bool resuelveCaso() {
	int Naguj = 0, Lparch = 0, pos1 = 0, pos2 = 0, Nparch = 0;

	std::cin >> Naguj >> Lparch >> pos1;
	if (!std::cin) return false;

    for (int i = 1; i < Naguj; ++i) {
		std::cin >> pos2;
		if (pos2 - pos1 > Lparch) {
			++Nparch;
			pos1 = pos2;
		}
	}
	++Nparch;
	std::cout << Nparch << '\n';
	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}