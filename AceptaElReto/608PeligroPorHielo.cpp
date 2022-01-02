#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int n, sol, x;
	bool reset;
	cin >> n;
	while (n != 0) {
		reset = true;
		sol = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (reset && x <= 4) {
				reset = false;
				++sol;
			}

			if (!reset && x > 6) reset = true;
		}

		cout << sol << '\n';
		cin >> n;
	}
}