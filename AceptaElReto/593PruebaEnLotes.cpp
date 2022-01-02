#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

int pruebas(int ini, int fin, vector<int> const& v, vector<int> const& muestra) {
	if (v[ini] == v[fin] && muestra[ini] != 1) return 1;
	if (ini == fin) return 1;

	int g1 = fin - ini + 1;
	if (g1 % 2 == 0) g1 /= 2;
	else g1 = g1 / 2 + 1;

	return 1 + pruebas(ini, ini + g1 - 1, v, muestra) + pruebas(ini + g1, fin,v, muestra);
}

int main() {
	int n;
	char x;
	cin >> n;
	while (n != 0) {
		vector<int> v(n), muestra(n);
		cin >> x;
		v[0] = int(x) - int('0');
		muestra[0] = v[0];
		for (int i = 1; i < n; ++i) {
			cin >> x;
			muestra[i] = int(x) - int('0');
			v[i] = v[i - 1] + muestra[i];
		}

		cout << pruebas(0, n - 1, v, muestra) << '\n';

	cin >> n;
	}

return 0;
}