#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/* We have the restrictions c = a^2 - b <---> a^2 = c+b and c^2 = a^2 + b^2 <--->  a^2 = c^2 - b^2
   This means c+b = c^2 - b^2 = (c+b)(c-b) or equivalently c-b = 1, they are consecutive numbers.
   Substituting we get a^2 = 2b + 1, so we can iterate over a to get the corresponding c = b+1 values, and this
   is O(sqrt n) because a ~ sqrt(c) <= sqrt(n)
*/

using namespace std;
#define ll long long

int main() {
	int tc, n, sol;
	cin >> tc;
	while (tc--) {
		cin >> n;
		sol = 0;
		for (ll a = 3; (a*a - 1) / 2 + 1 <= n; a += 2) ++sol;

		cout << sol << '\n';
	}
	
return 0;
}