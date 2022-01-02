#include <iostream>
#include <set>

bool cubifinito(long long int x,std::set<long long int> conj) {
	if (x == 1) return true;
	else {
		//buscarlo en el conjunto
		std::set<long long int>::iterator it = conj.find(x);
		if (it != conj.end()) return false;
		else {
			conj.insert(x);
			//obtener la suma de sus digitos al cubo
			long long int sum = 0;
			int aux;
			while (x > 0) {
				aux = x % 10;
				sum += aux * aux*aux;
				x /= 10;
			}

			std::cout << " - " << sum;
			return cubifinito(sum,conj);
		}

	}
}

int main() {
	long long int x;
	std::cin >> x;
	while (x != 0) {
		std::set<long long int> conj;
		std::cout << x;

		if (cubifinito(x,conj)) std::cout << " -> cubifinito.\n";
		else std::cout << " -> no cubifinito.\n";

		std::cin >> x;
	}

	return 0;
}