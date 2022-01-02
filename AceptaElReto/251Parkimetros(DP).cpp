#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, cap, sol, ind, aux, res;
	cin >> tc;
	while (tc--) {
		cin >> n >> cap;
		vector<int> vals(n);
		for (int i = 0; i < n; ++i) {
			cin >> vals[i];
		}
		sort(vals.begin(), vals.end());
		vector<int> can(cap * vals[vals.size() - 1] + 1, cap + 1);
		sol = 0;
		ind = 0;
		for (int i = 1; i < can.size(); ++i) {
			if (ind < n && vals[ind] == i) {
				++ind;
				++sol;
				can[i] = 1;
			}
			else {
				res = cap + 1;
				for (int j = 0; j < n && i > vals[j]; ++j) {
					aux = can[i - vals[j]] + 1;
					if (aux <= cap && aux < res) res = aux;
				}
				can[i] = res;
				if (res <= cap) ++sol;
			}
		}
		cout << sol << '\n';
	}
}