#include <iostream>
#include <vector>

const int MAX = 262144;//2^18

int main() {
	int N,fin, aux, calc;
	std::cin >> N;
	while (N != 0) {
		if (N == 1) {
			std::cin >> aux;
			std::cout << "1\n";
		}
		else {
			std::vector<int> v(N,MAX);
			fin = N - 1;
			std::cin >> v[0];
			for (int i = 1; i < fin; ++i) {
				std::cin >> aux;
				calc = i + aux;

				if (calc == fin) {
					if (v[i] != MAX) {
						if (v[i] < v[fin]) v[fin] = v[i];
					}
					else if (i < v[fin]) v[fin] = i;
				}
				else {
					++calc;
					if (calc < fin) {
						if (v[i] != MAX) {
							if (v[i] < v[calc]) v[calc] = v[i];
						}
						else if (i < v[calc]) v[calc] = i;
					}
				}
			}
			std::cin >> aux;
			if (v[fin] != MAX) std::cout << v[fin] << '\n';
			else std::cout << N << '\n';
		}

	std::cin >> N;
	}
return 0;
}