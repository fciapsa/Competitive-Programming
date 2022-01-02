#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long

/* We can model this as a graph where problems are vertexes and each edge {i,j} has weight |2^i - 2^j|
   Suppose i > j, then weight as binary number has all bits to zero except those in the range [j,i). This implies
   every single edge in the graph has a unique weight.

   Now, from the statement we can deduce IQ has to increase every time we solve a different problem, so we can consider
   edges in increasing order. We can do that considering j from 2 to n and for each j consider i from j-1 to 1.

   Finally, solve it using dp with one parameter, where dp[i] is the maximum amount of points we can earn ending with
   problem i. Initially dp[i] = 0 for all i and we relax each value iterating over the edges {i,j} in the mentioned order.
   If tag_i != tag_j, then dp[i] = max(dp[i], dp[j] + gain) and dp[j] = max(dp[j], dp[i] + gain) simultaneously(using
   old values for dp[i] and dp[j]) where gain = |s_i - s_j|.
*/

int main() {
	ll tc, n, vi, vj, diff, sol;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<ll> tags(n), scores(n);
		for (int i = 0; i < n; ++i) cin >> tags[i];
		for (int i = 0; i < n; ++i) cin >> scores[i];

		vector<ll> dp(n);
		for (int j = 1; j < n; ++j) {
			for (int i = j - 1; i >= 0; --i) {
				if (tags[i] == tags[j]) continue;
				vi = dp[i];
				vj = dp[j];
				diff = abs(scores[i] - scores[j]);
				dp[i] = max(vi, vj + diff);
				dp[j] = max(vj, vi + diff);
			}
		}

		sol = 0;
		for (int i = 0; i < n; ++i) if (dp[i] > sol) sol = dp[i];
		cout << sol << '\n';
	}
return 0;
}