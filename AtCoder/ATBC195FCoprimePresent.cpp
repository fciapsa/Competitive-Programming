#include <iostream>
#include <vector>

using namespace std;
#define ll long long

/*DP WITH BITMASK*/
vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

int main() {
	std::ios::sync_with_stdio(false);
	ll a, b, sol = 0;
	cin >> a >> b;
	vector<ll> dp(1 << 20);

	dp[0] = 1;//the empty set
	int act;
	for (ll x = a; x <= b; ++x) {
		act = 0;
		//activate divisor bits
		for (int i = 0; i < 20; ++i) {
			if (x % primes[i] == 0) act |= (1 << i);
		}

		//if no conflict, count resulting sets
		for (int y = (1 << 20) - 1; y >= 0; --y) {
			if ((act & y) == 0) dp[act | y] += dp[y];
		}
	}

	for (int i = 0; i < (1 << 20); ++i) sol += dp[i];
	cout << sol << '\n';

	return 0;
}