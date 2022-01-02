#include <iostream>
#include <vector>

int main() {
	long int N, A;
	std::cin >> N >> A;
	while (N != 0 && A != 0) {
		std::vector<int> v(N);
		for (int i = 0; i < v.size(); ++i) {
			std::cin >> v[i];
		}

		long int sum = 1, max = 1, ini = v[0], p = 0, fin = v[0];

		for (int i = 1; i < v.size(); ++i) {
			fin = v[i];
			while (fin - ini + 1 > A) {
				--sum;
				++p;
				ini = v[p];
			}
			++sum;
			if (sum > max) max = sum;	
		}
		std::cout << max << '\n';

	std::cin >> N >> A;
	}
return 0;
}