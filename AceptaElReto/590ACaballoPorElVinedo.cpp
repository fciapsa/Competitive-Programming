#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long int;

int main() {
	int r, n, x, sol, ind, acum;
	bool first;
	cin >> r >> n;
	while (r != 0) {
		vector<int> uvas(r);
		cin >> uvas[0];
		for (int i = 1; i < r; ++i) {
			cin >> x;
			uvas[i] = x + uvas[i - 1];
		}

		if (uvas[r - 1] < n) cout << "IMPOSIBLE\n";
		else {
			sol = INT_MAX;
			auto it = uvas.begin();
			ind = 0;
			acum = 0;
			while (true) {
				auto it2 = lower_bound(it, uvas.end(), n);
				if (*it2 - acum < sol) sol = *it2 - acum;
				
				if (ind == 0) {
					n += uvas[0];
					acum += uvas[0];
				}
				else {
					n += (uvas[ind] - uvas[ind - 1]);
					acum += (uvas[ind] - uvas[ind - 1]);
				}
				++ind;

				if (uvas[r - 1] < n) break;
			}

			cout << sol << '\n';
		}


	cin >> r >> n;
	}

return 0;
}