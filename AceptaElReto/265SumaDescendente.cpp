#include <iostream>

int main() {
	int n, ans, pot, aux;
	std::cin >> n;
	while (n != 0) {
		ans = 0;
		aux = 0;
		pot = 1;
		while (n > 0) {
			aux += (n % 10) * pot;
			ans += aux;
			pot *= 10;
			n /= 10;
		}
		std::cout << ans << '\n';
	std::cin >> n;
	}
return 0;
}