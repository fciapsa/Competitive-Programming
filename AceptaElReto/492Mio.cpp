#include <iostream>

long long int mcd(long long int a, long long int b) {
	if (b == 0) return a;
	else {
		long long int aux = a;
		a = b;
		b = aux % a;
		return mcd(a, b);
	}
}

  
long long int mcm(long long int a, long long int b){
	return (a*b) / mcd(a, b);
}

bool resuelve() {
	long long int M, D, N;
	std::cin >> M >> D >> N;

	if (M == 0 && D == 0 && N == 0) return false;

		long long int sol = N / mcm(M, D);
		std::cout << sol << '\n';

return true;
}

int main() {
	while (resuelve());
return 0;
}