#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define ll long long

vector<ll> limits = { 999,999999,999999999,999999999999,999999999999999,999999999999999999 };
vector<ll> ncomas = { 0,1,2,3,4,5};

int main() {
	vector<ll> acum(6);
	acum[0] = 0;
	for (int i = 1; i < 6; ++i) acum[i] = (limits[i] - limits[i - 1]) * ncomas[i] + acum[i - 1];

	ll n, act = 1, sol = 0;
	cin >> n;
	int i = 0;
	while (limits[i] < n) ++i;
	if (i > 0) {
		sol = acum[i - 1];
		sol += ncomas[i] * (n - limits[i - 1]);
	}
	cout << sol << '\n';
	return 0;
}