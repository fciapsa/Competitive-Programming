#include <iostream>

//La solucion es el doble de la cantidad de divisores impares
//OTRO: Sacar todos los divisores por pares con el bucle hasta sqrt(n) y comprobar los que cumplen que 2*n/k + 1 - k es par
int main() {
	long long int k, sol, cont;
	std::cin >> k;
	sol = 1;
	while (k % 2 == 0) k /= 2;

	for (long long int i = 3; i * i <= k; i += 2) {
		cont = 0;
		while (k % i == 0) {
			++cont;
			k /= i;
		}
		if (cont > 0) sol *= (cont + 1);
	}
	if (k > 1) sol *= 2;
	std::cout << 2*sol << '\n';
    return 0;
}