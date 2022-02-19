#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define ll long long

int main() {
	ll b = 0, c = 0, ini1, fin1, ini2, fin2;
	cin >> b >> c;
	if (b < 0) {
		ini1 = b - c / 2;
		if (c <= 3) fin1 = b;
		else fin1 = b + (c - 2) / 2;

		ini2 = -b - (c - 1) / 2;
		fin2 = -b + (c - 1) / 2;
		if (fin1 >= ini2) cout << max(fin1, fin2) - min(ini1, ini2) + 1 << '\n';
		else cout << fin1 - ini1 + fin2 - ini2 + 2 << '\n';
	}
	else if (b == 0) {
		ini1 = b - c / 2;
		fin1 = b + (c - 1) / 2;
		cout << fin1 - ini1 + 1 << '\n';
	}
	else {
		ini2 = b - c / 2;
		if (c <= 3) fin2 = b;
		else fin2 = b + (c - 2) / 2;
		ini1 = -b - (c - 1) / 2;
		fin1 = -b + (c - 1) / 2;
		if (fin1 >= ini2) cout << max(fin1, fin2) - min(ini1, ini2) + 1 << '\n';
		else cout << fin1 - ini1 + fin2 - ini2 + 2 << '\n';
	}
	
return 0;
}