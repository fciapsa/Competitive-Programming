#include <iostream>

/* ESPECIFICACION

PRE-CONDICION: { L > 0}
             maxGanancia( v[0..L) de ent) dev max:ent
POST-CONDICION: { max = (max p,q: 0 <= p <= q < L: S1(p,q))
                max
				(max p,q: 0 <= p < L && 0 <= q < p: S2(p,q))
                }

                S1(p,q) = SUM i: p <= i <= q: v[i]
				S2(p,q) = SUM i: p <= i < L || 0 <= i <= q: v[i]

INVARIANTE 1: 
b : 
COTA 1: 

INVARIANTE 2: 
COTA 2:

*/

int main() {
	long int L;
	std::cin >> L;
	while (L != 0) {
		long int x;
		std::cin >> x;

		long int sum = x, max = x, bestIni = x, totSum = x;

		for (long int i = 1; i < L; ++i) {
			std::cin >> x;
			if (x >= sum + x) sum = x;
			else sum += x;

			totSum += x;
			if (totSum > bestIni) bestIni = totSum;

			if (sum > max) max = sum;
		}
		if (sum + bestIni > max) max = sum + bestIni;
		std::cout << max << '\n';

		std::cin >> L;
	}
	return 0;
}