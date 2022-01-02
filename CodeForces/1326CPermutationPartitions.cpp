#include <iostream>

/*La suma maxima que se puede obtener al particionar en k subconjuntos se puede calcular vorazmente como la suma de los k
mayores elementos.
La cantidad de dichas particiones que dan el valor maximo viene de la ambiguedad al colocar los limites entre los subconjuntos 
*/
const int MOD = 998244353;

int main() {
	long long int n, k;
	std::cin >> n >> k;
	long long int pos_ant = -1, x;
	long long int max = (k * (n - k + 1 + n)) / 2, sol;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		if (x + k > n) {//es uno de los k mayores
			if (pos_ant == -1) sol = 1;
			else {
				sol *= (i - pos_ant);
				sol %= MOD;
			}
			pos_ant = i;
		}
	}
	std::cout << max << ' ' << sol << '\n';
return 0;
}