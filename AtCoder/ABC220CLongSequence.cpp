#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll n, x;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 1; i < n; ++i) v[i] += v[i - 1];
    cin >> x;

    ll q = x / v[n - 1];
    ll sol = n * q, accum = q*v[n-1], ind = 0;
    while (accum + v[ind] <= x) {
        ++ind;
    }

    cout << sol + ind+1 << '\n';

    return 0;
}