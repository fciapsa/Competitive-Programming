#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = unsigned long long int;

int main() {
	ll n, max, sol, x;
	cin >> n;
	while (n != 0) {
		max = 0;
		sol = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (x > max) {
				sol += i * (x - max);
				max = x;
			}
			else sol += (max - x);
		}

		cout << sol << '\n';

	cin >> n;
	}

return 0;
}