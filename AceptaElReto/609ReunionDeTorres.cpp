#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int n, t, a, b, solRow = -1, bestRowVal, solCol = -1, bestColVal, aux;
	cin >> n >> t;
	while (cin) {
		vector<int> oncol(n + 1);
		vector<int> onrow(n + 1);

		for (int i = 0; i < t; ++i) {
			cin >> a >> b;
			++onrow[a];
			++oncol[b];
		}

		bestRowVal = INT_MAX;
		bestColVal = INT_MAX;

		for (int row = 1; row <= n; ++row) {
			aux = 0;
			for (int i = row - 1, k = 1; i >= 1 && aux < bestRowVal; --i, ++k) aux += k * onrow[i];
			for (int i = row + 1, k = 1; i <= n && aux < bestRowVal; ++i, ++k) aux += k * onrow[i];

			if (aux < bestRowVal) {
				bestRowVal = aux;
				solRow = row;
			}
		}

		for (int col = 1; col <= n; ++col) {
			aux = 0;
			for (int i = col - 1, k = 1; i >= 1 && aux < bestColVal; --i, ++k) aux += k * oncol[i];
			for (int i = col + 1, k = 1; i <= n && aux < bestColVal; ++i, ++k) aux += k * oncol[i];

			if (aux < bestColVal) {
				bestColVal = aux;
				solCol = col;
			}
		}

		cout << solRow << ' ' << solCol << '\n';

	cin >> n >> t;
	}
}