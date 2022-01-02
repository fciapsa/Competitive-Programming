#include <iostream>
#include <vector>
#include <algorithm>//sort

int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> v[i];
		}

		sort(v.begin(), v.end());
		int moda = v[0], contModa = 1, cont = 1;
		for (int i = 1; i < n; ++i) {
			if (v[i] == v[i - 1]) ++cont;
			else {
				if (cont > contModa) {
					moda = v[i - 1];
					contModa = cont;
				}
				cont = 1;
			}
		}
		if (cont > contModa) moda = v[v.size()-1];

		std::cout << moda << '\n';
		std::cin >> n;
	}
return 0;
}