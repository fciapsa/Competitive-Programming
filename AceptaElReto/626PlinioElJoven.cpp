#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, dd, mm, aa;
	char ch;
	cin >> tc;
	while (tc--) {
		cin >> dd >> ch >> mm >> ch >> aa;
		cout << "29/02/";
		if (aa % 4 == 0) {
			if (mm > 2 || (mm == 2 && dd == 29)) {
				cout << setw(4) << setfill('0') << aa + 4 << '\n';
			}
			else cout << setw(4) << setfill('0') << aa << '\n';
		}
		else cout << setw(4) << setfill('0') << aa + (4-aa%4) << '\n';
	}
	return 0;
}