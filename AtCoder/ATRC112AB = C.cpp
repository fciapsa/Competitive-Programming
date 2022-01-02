#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define ll long long

int main() {
	ll t, l, r, x;
	cin >> t;
	while (t--) {
		cin >> l >> r;
		if (r < 2 * l) cout << "0\n";
		else {
			x = r - 2 * l + 1;
			cout << (x * (x + 1)) / 2 << '\n';
		}
	}

return 0;
}