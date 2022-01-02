#include <bits/stdc++.h>

using namespace std;
#define ll long long

map<ll,map<ll,ll>> dp;

ll comb(ll n, ll k) {
    if (k == 0 || k == n) return 1;
    if (k == 1 || k == n-1) return n;

    if (dp.count(n) && dp[n].count(k)) return dp[n][k];

    return dp[n][k] = comb(n - 1, k) + comb(n - 1, k - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    while (n != 0) {
        cout << comb(n, k) << '\n';
        cin >> n >> k;
    }
    return 0;
}