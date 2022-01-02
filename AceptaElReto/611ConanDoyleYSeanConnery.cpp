#include <iostream>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int y, n, x, cont, min;
	string a, p, sol;
	cin >> y;
	while (cin) {
		getline(cin, a);

		min = 10001;
		cont = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			cin.ignore();
			getline(cin, p);

			if (x >= y) {
				++cont;
				if (x < min) {
					min = x;
					sol = p;
				}
			}
		}

		if (cont == n) cout << "TODAS\n";
		else if (cont == 0) cout << "NINGUNA\n";
		else cout << sol << '\n';

	cin >> y;
	}
}