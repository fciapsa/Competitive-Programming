#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> dm = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct fecha {
	int dd, mm, aa;
	void sumar(int tiempo) {
		while (tiempo) {
			if (mm != 2) {
				if (tiempo > dm[mm] - dd) {
					tiempo -= (dm[mm] - dd + 1);
					dd = 1;
					mm = mm + 1;
					if (mm == 13) {
						mm = 1;
						aa = aa + 1;
					}
				}
				else {
					dd += tiempo;
					tiempo = 0;
				}
			}
			else {
				if (aa % 4 == 0) {
					if (tiempo > 29 - dd) {
						tiempo -= (29 - dd + 1);
						dd = 1;
						mm = mm + 1;
					}
					else {
						dd += tiempo;
						tiempo = 0;
					}
				}
				else {
					if (tiempo > 28 - dd) {
						tiempo -= (28 - dd + 1);
						dd = 1;
						mm = mm + 1;
					}
					else {
						dd += tiempo;
						tiempo = 0;
					}
				}
			}
		}
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	int dd, mm, aa, anyos, meses, dias, tiempo;
	fecha f;
	char ch;
	cin >> dd >> ch >> mm >> ch >> aa >> anyos >> meses >> dias;
	while (aa != 0) {
		tiempo = anyos * 12 * 28 + meses * 28 + dias;
		f = { dd,mm,aa };
		f.sumar(tiempo);
		cout << setw(2) << setfill('0') << f.dd << '/';
		cout << setw(2) << setfill('0') << f.mm << '/';
		cout << setw(4) << setfill('0') << f.aa << '\n';
		cin >> dd >> ch >> mm >> ch >> aa >> anyos >> meses >> dias;
	}
	return 0;
}