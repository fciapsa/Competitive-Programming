#include <iostream>
#include <vector>
#include <string>

long long int fib(int n, std::vector<long long int> &numsFib) {
	if (numsFib[n] != -1) return numsFib[n];

	if (n == 0) {
		numsFib[0] = 0;
		return 0;
	}
	if (n == 1) {
		numsFib[1] = 1;
		return 1;
	}

	long long int iz, dr;
	if (numsFib[n - 2] != -1) iz = numsFib[n - 2];
	else iz = fib(n - 2,numsFib);
	if (numsFib[n - 1] != -1) dr = numsFib[n-1];
	else dr = fib(n - 1,numsFib);

	numsFib[n] = iz + dr;
	return iz + dr;
}

void dibujar(int n, long long int nivel,std::vector<long long int> const& numsFib) {
	long long int espacios = nivel * 3;
	std::string aux = "";
	for (long long int i = 0; i < espacios; ++i) aux += ' ';
	std::cout << aux << numsFib[n] << '\n';
	if (n >= 2) {
		dibujar(n - 2, nivel + 1,numsFib);
		dibujar(n - 1, nivel + 1,numsFib);
	}
	
}

int main() {
	int n;
	std::cin >> n;
	std::string FIN = "====\n";
	while (n >= 0) {
		std::vector<long long int> numsFib(n+1, -1);
		fib(n, numsFib);
		dibujar(n, 0,numsFib);
		std::cout << FIN;
	std::cin >> n;
	}
return 0;
}