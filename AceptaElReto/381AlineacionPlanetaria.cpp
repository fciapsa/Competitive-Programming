#include <iostream>
#include <vector>

long long int MCD(long long int const& a, long long int const& b) {
	if (a % b == 0) return b;
	else return MCD(b, a%b);
}

int main() {
	int n;
	long long int mcm;
	std::cin >> n;
	while (n != 0) {
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) std::cin >> v[i];

		mcm = (v[0]/ MCD(v[0], v[1]))*v[1];
		for (int i = 2; i < n; ++i) {
			mcm = (mcm/ MCD(mcm, v[i]))*v[i];
		}

		std::cout << mcm << '\n';

	std::cin >> n;
	}
return 0;
}