#include <iostream>

const int K = 31543;

long long int pot(long long int b, long long int e) {
	if (e == 0) return 1;
	else {
		long long int aux = pot(b, e / 2) % K;
		if (e % 2 == 0) return (aux*aux) % K;
		else return ((aux*aux) * b) % K;
	}
}

int main() {
	long long int b, e;
	std::cin >> b >> e;
	while (b != 0 || e != 0) {
		b %= K;
		std::cout << pot(b, e) << '\n';
		std::cin >> b >> e;
	}
	return 0;
}