#include <iostream>

int numCif(long long int n) {
	int cif = 1;
	while (n / 10 > 0) {
		n /= 10;
		++cif;
	}
return cif;
}

bool poliDiv(long long int n, int cif) {
	if (n < 10) return true;
	else return (n%cif == 0) && poliDiv(n / 10, cif - 1);
}

int main(){
	long long int n;
	std::cin >> n;
	while (std::cin) {
		int cif = numCif(n);
		bool b = poliDiv(n,cif);
		if (b) std::cout << "POLIDIVISIBLE\n";
		else std::cout << "NO POLIDIVISIBLE\n";
		std::cin >> n;
	}
return 0;
}