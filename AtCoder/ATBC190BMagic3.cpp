#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, s, d, xs, ys;
	cin >> n >> s >> d;
	bool dmg = false;
	for (int i = 0; i < n; ++i) {
		cin >> xs >> ys;
		if (xs < s && ys > d) dmg = true;
	}
	if (dmg) cout << "Yes\n";
	else cout << "No\n";

		return 0;
}