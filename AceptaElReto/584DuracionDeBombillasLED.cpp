#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

int main() {
	int t, tot, enc, time, aux;
	cin >> t;
	while (t--) {
		cin >> tot >> enc >> time;
		aux = enc * time;
		if (aux == tot) cout << "AMBAS\n";
		else if (aux < tot) cout << "ENCENDIDOS\n";
		else cout << "HORAS\n";
	}

return 0;
}