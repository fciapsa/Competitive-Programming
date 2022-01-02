#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int n, mod, ans;
	while (cin >> n) {
		ans = 1;
		mod = 1;
		while (mod = mod % n) {
			++ans;
			mod = 10 * mod + 1;
		}

		cout << ans << '\n';
	}
}