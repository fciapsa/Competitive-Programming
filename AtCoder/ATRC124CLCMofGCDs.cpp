#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <utility>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

//GCD produces a decreasing sequence when increasing N, so there shouldn't be too many pairs at each stage

int main() {
    std::ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n;
    
    set<pair<ll, ll>> dp = { {0,0} }, dp2;//dp -> current stage possible (gcd1, gcd2) pairs, dp2 -> next stage
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        dp2.clear();
        for (auto p : dp) {
            dp2.insert({ gcd(p.first, a), gcd(p.second, b) });
            dp2.insert({ gcd(p.first, b), gcd(p.second, a) });
        }
        swap(dp, dp2);
    }

    ll ans = 0, aux;
    for (auto p : dp) {
        aux = lcm(p.first, p.second);
        if (aux > ans) ans = aux;
    }

    cout << ans << '\n';

    return 0;
}