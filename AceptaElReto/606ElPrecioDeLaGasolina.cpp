#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

//O(n^2) solution, but O(n*logn) exists

int main() {
	std::ios::sync_with_stdio(false);

	int n, llis;
	cin >> n;
	while (n != 0) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];

		vector<int> dp(n, 1);//dp[i] = Length of Longest Increasing Subsequence ending at v[i] (included)
		llis = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (v[j] < v[i]) dp[i] = max(dp[i], 1 + dp[j]);
			}
			if (dp[i] > llis) llis = dp[i];
		}

		cout << llis << '\n';

    cin >> n;
	}
}