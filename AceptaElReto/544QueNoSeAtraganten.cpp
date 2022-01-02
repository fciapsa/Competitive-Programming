#include <iostream>
#include <vector>
#include <climits>

bool resuelve() {
	long long int N, P;
	std::cin >> N >> P;

	if(!std::cin) return false;

	std::vector<long long int> pesos;
	long long int aux, cont = 0, max_peque = LLONG_MIN, min_grande = LLONG_MAX;
	for (long long int i = 0; i < N; ++i) {
		std::cin >> aux;
		if (aux <= P / 2 || (N==1 && aux < P)) {
			++cont;
			if (aux > max_peque) max_peque = aux;
		}
		else if (aux < min_grande) min_grande = aux;
	}

	if (cont > 0 && min_grande < LLONG_MAX && max_peque + min_grande <= P) std::cout << cont + 1 << '\n';
	else if (cont == 0 && min_grande <= P) std::cout << "1\n";
	else std::cout << cont << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}