#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long

const int MOD = 1000000007;

ll pot(ll base, ll expo) {
    if (expo == 0) return 1;

    ll res;
    res = pot(base, expo / 2);
    if (expo % 2) return (((res * res) % MOD) * base) % MOD;
    else return (res * res) % MOD;
}

int main() {
    std::ios::sync_with_stdio(false);
    ll n, p;
    cin >> n >> p;

    cout << ((p - 1) * pot(p - 2, n - 1)) % MOD << '\n';

    return 0;
}