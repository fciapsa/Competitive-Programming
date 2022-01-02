#include <iostream>

int main() {
	long long int N, n1, n2;
	std::cin >> N;

	while (N != 0){
		bool crec = true, decrec = true;
		std::cin >> n1 >> n2;
		crec = n1 < n2;
		decrec = n1 > n2;

		int i = 2;
		while (i < N && (crec || decrec)) {
			n1 = n2;
			std::cin >> n2;
			crec = n1 < n2 && crec;
			decrec = n1 > n2 && decrec;
			++i;
		}
		for (; i < N; ++i) {
			std::cin >> n2;
		}

		if (crec || decrec) std::cout << "DALTON\n";
		else std::cout << "DESCONOCIDOS\n";

		std::cin >> N;
	}
return 0;
}