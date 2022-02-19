#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	std::ios::sync_with_stdio(false);
	ll x;
	cin >> x;
	if (x < 0) {
		ll aux = -x;
		if (aux % 10) cout << -aux / 10 - 1 << '\n';
		else cout << -aux / 10 << '\n';
	}
	else cout << x / 10 << '\n';
	return 0;
}