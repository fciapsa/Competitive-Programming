#include <iostream>
#include <string>
#include <vector>
#include <cmath>

long long int gcd(long long int a,long long int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Returns LCM of array elements 
long long int findlcm(std::vector<long long int> const&arr)
{
	// Initialize result 
	long long int ans = arr[0];

	// ans contains LCM of arr[0], ..arr[i] 
	// after i'th iteration, 
	for (int i = 1; i < arr.size(); ++i) {
		ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
	}

	return ans;
}

long long int toNum(std::string const&s) {
	long long int sol = 0;
	long long int pot = 1;
	for (int i = s.size() - 1; i >= 0; --i) {
		sol += (int(s[i]) - int('0')) * pot;
		pot *= 10;
	}
return sol;
}

bool resuelve() {
	int com;
	std::cin >> com;

	if (com == 0) return false;

	std::vector<long long int> vn(com);//numeradores
	std::vector<long long int> vd(com);//denominadores

	std::string aux;
	std::cin >> aux;

	int start = 0, fin = 0;
	while (aux[fin] != '/') ++fin;
	long long int A = toNum(aux.substr(start, fin - start));
	start = fin + 1;
	long long int B = toNum(aux.substr(start, aux.size()-start));

	int i = 1;
	vn[0] = A;
	vd[0] = B;

	while (i < com) {
		std::cin >> aux;

		start = 0, fin = 0;
		while (aux[fin] != '/') ++fin;
		A = toNum(aux.substr(start, fin - start));
		start = fin + 1;
		B = toNum(aux.substr(start, aux.size() - start));

		vn[i] = A;
		vd[i] = B;
		++i;
	}
	
	long long int mac = findlcm(vd);
	long long int sol = mac;
	for (int i = 0; i < com; ++i) {
		sol -= (mac / vd[i])*vn[i];
	}
	std::cout << sol << '\n';

return true;
}

int main() {
	while(resuelve());
return 0;
}