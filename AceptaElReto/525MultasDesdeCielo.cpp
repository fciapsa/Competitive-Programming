#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int a, b, c, d, aux;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b >> c >> d;

		if (b < a) {
			aux = b;
			b = a;
			a = aux;
		}
		if (d < c) {
			aux = d;
			d = c;
			c = aux;
		}
		
		if ((c < a && a < d )|| (c < b && b < d) || (a < c && c < b) || (a < d && d < b) || (a == c && b == d))std::cout << "SOLAPADOS\n";
		else std::cout << "SEPARADOS\n";
		
	}

return 0;
}