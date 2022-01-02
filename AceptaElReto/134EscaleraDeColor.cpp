#include <iostream>
#include <vector>
#include <algorithm>

const int MANO = 4;

int main() {
	bool ok;
	std::vector<int> cartas(MANO);
	char palo, c, val, aux;
	std::cin >> val;
	while (val != '0') {
		std::cin.get(aux);
		if (aux == '0') cartas[0] = 10;
		else {
			switch (val) {
			case '2': cartas[0] = 2; break;
			case '3': cartas[0] = 3; break;
			case '4': cartas[0] = 4; break;
			case '5': cartas[0] = 5; break;
			case '6': cartas[0] = 6; break;
			case '7': cartas[0] = 7; break;
			case '8': cartas[0] = 8; break;
			case '9': cartas[0] = 9; break;
			case 'J': cartas[0] = 11; break;
			case 'Q': cartas[0] = 12; break;
			case 'K': cartas[0] = 13; break;
			case 'A': cartas[0] = 14; break;
			}
		}
		std::cin >> palo;
		ok = true;
		for (int i = 1; i < MANO; ++i) {
			std::cin >> val;
			std::cin.get(aux);
			if (aux == '0') cartas[i] = 10;
			else {
				switch (val) {
				case '2': cartas[i] = 2; break;
				case '3': cartas[i] = 3; break;
				case '4': cartas[i] = 4; break;
				case '5': cartas[i] = 5; break;
				case '6': cartas[i] = 6; break;
				case '7': cartas[i] = 7; break;
				case '8': cartas[i] = 8; break;
				case '9': cartas[i] = 9; break;
				case 'J': cartas[i] = 11; break;
				case 'Q': cartas[i] = 12; break;
				case 'K': cartas[i] = 13; break;
				case 'A': cartas[i] = 14; break;
				}
			}
			std::cin >> c;
			if (c != palo) ok = false;
		}

		if (!ok) std::cout << "NADA\n";//no todos del mismo palo
		else {
			sort(cartas.begin(), cartas.end());

			bool hueco = false;
			int pos = -1;
			for (int i = 1; i < MANO; ++i) {
				if (cartas[i] != cartas[i - 1] + 1) {
					if (!hueco && cartas[i] == cartas[i - 1] + 2) {
						hueco = true;
						pos = i;
					}
					else ok = false;
				}
			}
			if (!ok) std::cout << "NADA\n";//no son valores consecutivos
			else if (hueco) {
				switch (cartas[pos]-1) {
				case 3:std::cout << 3 << ' ' << palo << '\n'; break;
				case 4: std::cout << 4 << ' ' << palo << '\n'; break;
				case 5: std::cout << 5 << ' ' << palo << '\n'; break;
				case 6: std::cout << 6 << ' ' << palo << '\n'; break;
				case 7: std::cout << 7 << ' ' << palo << '\n'; break;
				case 8: std::cout << 8 << ' ' << palo << '\n'; break;
				case 9: std::cout << 9 << ' ' << palo << '\n'; break;
				case 10: std::cout << 10 << ' ' << palo << '\n'; break;
				case 11: std::cout << "J " << palo << '\n'; break;
				case 12: std::cout << "Q " << palo << '\n'; break;
				case 13: std::cout << "K " << palo << '\n'; break;
				}
			}
			else {
				switch (cartas[MANO - 1]) {
				case 5: std::cout << 6 << ' ' << palo << '\n'; break;
				case 6: std::cout << 7 << ' ' << palo << '\n'; break;
				case 7: std::cout << 8 << ' ' << palo << '\n'; break;
				case 8: std::cout << 9 << ' ' << palo << '\n'; break;
				case 9: std::cout << 10 << ' ' << palo << '\n'; break;
				case 10: std::cout << "J " << palo << '\n'; break;
				case 11: std::cout << "Q " << palo << '\n'; break;
				case 12: std::cout << "K " << palo << '\n'; break;
				case 13: std::cout << "A " << palo << '\n'; break;
				case 14: std::cout << 10 << ' ' << palo << '\n'; break;
				}
			}
		}

	std::cin >> val;
	}
return 0;
}