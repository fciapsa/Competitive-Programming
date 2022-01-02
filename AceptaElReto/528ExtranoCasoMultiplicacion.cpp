#include <iostream>

int main() {
	long long int N, lt1, ones, gt1, zeroes;
	double x;
	long long int sol;
	std::cin >> N;
	while (N != 0) {
		lt1 = 0;
		ones = 0;
		gt1 = 0; 
		zeroes = 0;
		for (int i = 0; i < N; ++i) {
			std::cin >> x;
			if (x == 0.0) ++zeroes;
			else if (x == 1.0) ++ones;
			else if (x < 1.0) ++lt1;
			else ++gt1;
		}
		sol = (zeroes * ((N - 1 + N - zeroes)) / 2) + ((lt1 + ones - 1) * (lt1 + ones)) / 2 + 
			ones * gt1 + ((gt1-1)*(gt1)) / 2;
		std::cout << sol << '\n';
	std::cin >> N;
	}
return 0;
}