#include <iostream>
#include <vector>

const long long int MOD = 1000000007;
std::vector<long long int> inversoModular(5001);

int modInverse(int a,int m)
{
	int m0 = m;
	int y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1)
	{
		// q is quotient 
		int q = a / m;
		int t = m;

		// m is remainder now, process same as 
		// Euclid's algo 
		m = a % m, a = t;
		t = y;

		// Update y and x 
		y = x - q * y;
		x = t;
	}

	// Make x positive 
	if (x < 0)
		x += m0;

	return x;
}

int main() {
	for (int i = 1; i <= 5000; ++i) inversoModular[i] = modInverse(i, MOD);
	int n, m;
	long long int aux;
	std::cin >> n >> m;
	while (n != 0) {
		aux = 1;
		std::cout << 1;
		for (long long int i = 1, j = n; i <= m; ++i, --j) {
			aux = (((aux * j)%MOD) * inversoModular[i]) % MOD;
			std::cout << ' ' << aux;
		}		
		std::cout << '\n';
	std::cin >> n >> m;
	}
return 0;
}