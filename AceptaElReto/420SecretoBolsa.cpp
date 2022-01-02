#include <iostream>
#include <string>

void resuelveCaso() {
	int key;
	std::string dig;
	std::cin >> key >> dig;

	int sum = 0, num, cont = 0;
	long long int p = 0;

	for (long long int i = 0; i < dig.size(); ++i) {
		num = int(dig[i]) - '0';
		if (sum + num < key) {
			sum += num;
		}
		else if (sum + num == key) {
			++cont;
			sum += num;
		}
		else {
			while (sum + num > key) {
				sum -= int(dig[p]) - '0';
				++p;
			}
			if (sum + num < key) {
				sum += num;
			}
			else if (sum + num == key) {
				++cont;
				sum += num;
			}
		}
	}
	std::cout << cont << '\n';
}

int main() {
	int nCasos;
	std::cin >> nCasos;
	for (int i = 0; i < nCasos; ++i) {
		resuelveCaso();
	}
return 0;
}