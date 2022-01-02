#include <iostream>

using namespace std;
#define ll long long

ll pow2[53];

//0 is left, 1 is right
ll solve(ll n, ll h, int dir) {
	if (h == 0) return 0;

	ll sub_size = pow2[h] - 1;
	ll sub_leafs = pow2[h - 1];
	if (dir == 0) {
		if (n > sub_leafs) return 1 + sub_size + solve(n - sub_leafs, h - 1, 0);
		else return 1 + solve(n, h - 1, 1);
	}
	else {
		if (n > sub_leafs) return 1 + solve(n - sub_leafs, h - 1, 0);
		else return 1 + sub_size + solve(n, h - 1, 1);
	}
}

int main() {
	pow2[0] = 1;
	for (int i = 1; i <= 50; ++i) pow2[i] = 2 * pow2[i - 1];
	ll h, n;
	cin >> h >> n;
	cout << solve(n, h, 0) << '\n';
	return 0;
}