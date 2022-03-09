#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll factorial(ll x) {
    ll res = 1;
    for (ll i = 2; i <= x; ++i) res *= i;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    vector<ll> der(11);
    der[0] = 1;
    der[1] = 0;
    for (int i = 2; i < 11; ++i) der[i] = (i - 1) * (der[i - 1] + der[i - 2]);

    ll n;
    cin >> n;
    if (n <= 10) {
        ll fact = factorial(n);
        cout << fixed << setprecision(7) << 1 - (double)der[n] / fact << '\n';
    }
    else cout << 0.6321206 << '\n';

    return 0;
}