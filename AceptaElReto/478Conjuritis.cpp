#include <iostream>
#include <vector>

int main() {
	int N, i1, i2, aux;
	long long int tot, dif;
	bool found;
	std::cin >> N;
	while (N != 0) {
		std::vector<int> v(N);
		tot = 0;
		for (int i = 0; i < N; ++i) {
			std::cin >> v[i];
			tot += v[i];
		}
		std::cin >> dif;
		dif = tot - dif;
		found = false;
		i1 = 0;
		i2 = N - 1;
		while (!found) {
			aux = v[i1] + v[i2];
			if (aux > dif) --i2;
			else if (aux < dif) ++i1;
			else found = true;
		}

		std::cout << v[i1] << ' ' << v[i2] << '\n';

	std::cin >> N;
	}
return 0;
}