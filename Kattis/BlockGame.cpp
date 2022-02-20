#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool unique_even(ll n, ll m) {
	if (n % m == 0 || n > 2*m) return true;
	return m % (n - m) && m <= 2 * (n - m) && unique_even(n - m, m % (n - m));
}

int main() {
	std::ios::sync_with_stdio(false);
	ll n, m, turn;
	cin >> n >> m;
	if (n < m) swap(n, m);
	if (n % m == 0) cout << "win\n";
	else if (n > 2 * m || unique_even(n, m)) cout << "win\n";
	else cout << "lose\n";
	return 0;
}