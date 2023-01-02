#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll numZeroesOfFact(ll x) {
    ll zeroes = 0, q = 5;
    while (q <= x) {
        zeroes += x / q;
        q *= 5;
    }
    return zeroes;
}

ll minFactWith(ll n) {
    ll ini = 0, fin = 5 * n;

    ll ret;
    while (ini <= fin){
        ll m = (ini + fin)/2;

        if (numZeroesOfFact(m) >= n) {
            ret = m;
            fin = m - 1;
        }
        else ini = m + 1;
    }

    return max((ll)1,ret);
}

int main() {
    std::ios::sync_with_stdio(false);
    ll d, n;
    cin >> d >> n;
    while (d) {
        ll ans = minFactWith(n);
        bool found = false;
        while (!found && numZeroesOfFact(ans) == n) {
            if (ans % d == 0) {
                found = true;
                cout << ans << '\n';
            }
            ++ans;
        }
        if (!found) cout << "NINGUNO\n";

        cin >> d >> n;
    }

    return 0;
}