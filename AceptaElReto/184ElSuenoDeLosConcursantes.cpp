#include <iostream>

const int MIN = 1320;//se van a dormir minimo a las 22:00
const int MAX = 1440;//maximo de minutos en un dia

int main() {
	int N, h1, m1, h2, m2, tot, aux1, aux2;
	char aux;
	std::cin >> N;
	while (N != 0) {
		tot = 0;
		for (int i = 0; i < N; ++i) {
			std::cin >> h1 >> aux >> m1 >> aux >> h2 >> aux >> m2;
			aux1 = 60 * h1 + m1;
			aux2 = 60 * h2 + m2;
			if (aux1 >= MIN && aux2 > MIN) tot += (aux2 - aux1);
			else if (aux1 >= MIN) tot += (MAX - aux1 + aux2);
			else tot += (aux2 - aux1);
		}
		h1 = tot / 60;
		m1 = tot % 60;
		if (h1 < 10) std::cout << '0';
		std::cout << h1 << ':';
		if (m1 < 10) std::cout << '0';
		std::cout << m1 << '\n';
	std::cin >> N;
	}
return 0;
}