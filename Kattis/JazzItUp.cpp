#include <bits/stdc++.h>

using namespace std;
#define ll long long

bitset<100001> bs;
vector<ll> primes;
//Criba de Eratostenes
void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < bs.size(); i++)
		if (bs[i]) {
			for (ll j = i * i; j < bs.size(); j += i) bs[j] =
				0;
			primes.push_back(i);
		}
}

int main() {
	std::ios::sync_with_stdio(false);
	sieve();
	int n;
	cin >> n;
	if (n == 2) cout << "3\n";
	else if (bs[n]) cout << "2\n";
	else {
		for (int i = 0; i < primes.size(); ++i)
			if (n % primes[i]) {
				cout << primes[i] << '\n';
				break;
		    }
	}

	return 0;
}