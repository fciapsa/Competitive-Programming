#include <iostream>
#include <cmath>

/*Analizando los primeros casos se observa que:
    El disco k se mueve 2^(n-k) veces
	El disco k se mueve por primera vez en el movimiento 2^(k-1)
	El disco k se mueve cada 2^k movimientos tras el primero
*/

int main() {
	long long int k, n, veces, aux, aux2;
	std::cin >> k >> n;
	while (k != 0) {
		veces = pow(2, n - k);
		if (veces > k) {
			aux = pow(2, k - 1) + (k - 1) * pow(2, k);
			veces -= k;
			aux2 = pow(2, k - 1) + (veces - 1) * pow(2, k);
			std::cout << k << ' ' << n << ' ' << aux << ' ' << aux2 << '\n';
		}
		else if (veces == k) {
			aux = pow(2, k - 1) + (k - 1) * pow(2, k);
			std::cout << k << ' ' << n << ' ' << aux << " -1\n";
		}
		else std::cout << k << ' ' << n << " -1 -1\n";

	std::cin >> k >> n;
	}
return 0;
}