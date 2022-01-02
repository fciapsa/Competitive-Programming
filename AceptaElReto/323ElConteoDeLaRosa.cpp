#include <iostream>
#include <vector>

int main() {
	int n1,cn1, n2, pot, nextpot, nd, tot, d1, d2, aux, pag1;
	std::cin >> n1 >> n2;
	while (n1 != 0) {
		pot = 1;
		nd = 1;
		while (pot < n1) {
			pot *= 10;
			++nd;
		}

		if (pot > n1) {
			pot /= 10;
			--nd;
		}
		nextpot = pot * 10;

		tot = 0;
		cn1 = n1;
		while (n2 >= nextpot) {
			tot += nd * (nextpot - cn1);
			cn1 = nextpot;
			nextpot *= 10;
			++nd;
		}
		tot += nd * (n2 - cn1+1);

		//AGAIN
		pot = 1;
		nd = 1;
		while (pot < n1) {
			pot *= 10;
			++nd;
		}

		if (pot > n1) {
			pot /= 10;
			--nd;
		}
		nextpot = pot * 10;

		d1 = 0;
		pag1 = 0;
		d2 = tot;
		cn1 = n1;
		aux = nd * (nextpot - cn1);
		while (d1 + aux <= d2 - aux) {
			pag1 += nextpot - cn1;
			d1 += aux;
			d2 -= aux;
			cn1 = nextpot;
			nextpot *= 10;
			++nd;
			aux = nd * (nextpot - cn1);
		}
		pag1 += ((d2 - d1) / nd) / 2;

		std::cout << n1+pag1-1 << '\n';
	std::cin >> n1 >> n2;
	}
return 0;
}