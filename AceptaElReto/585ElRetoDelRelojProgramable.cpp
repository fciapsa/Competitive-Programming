#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

int main() {
	int t;
	double a1, a2, aux1, aux2;
	int hh, mm;
	cin >> t;
	while (t--) {
		cin >> a1 >> a2;
		aux1 = a1;
		aux2 = a2;
		hh = 0;
		mm = 0;
		while (aux1 >= 30) {
			aux1 -= 30;
			++hh;
		}
		while (aux1 >= 0.5) {
			aux1 -= 0.5;
			++mm;
		}
		if (mm * 6 == aux2 && aux1 == 0) {
			if (hh < 10) cout << "0";
			cout << hh << ':';
			if(mm < 10) cout << "0";
			cout << mm << '\n';
		}
		else {
			aux1 = a2;
			aux2 = a1;
			hh = 0;
			mm = 0;
			while (aux1 >= 30) {
				aux1 -= 30;
				++hh;
			}
			while (aux1 >= 0.5) {
				aux1 -= 0.5;
				++mm;
			}
			if (mm * 6 == aux2 && aux1 == 0) {
				if (hh < 10) cout << "0";
				cout << hh << ':';
				if (mm < 10) cout << "0";
				cout << mm << '\n';
			}
			else cout << "ERROR\n";
		}
	}

return 0;
}