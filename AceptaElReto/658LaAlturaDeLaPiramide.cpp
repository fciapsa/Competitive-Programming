#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll necesario(ll niveles) {
    return (niveles * (2 * niveles + 1) * (2 * niveles - 1)) / 3;
}

bool posible(ll piedras, ll niveles) {
    return necesario(niveles) <= piedras;
}

int main() {
    std::ios::sync_with_stdio(false);
    ll n, ini, fin, m, ans;
    cin >> n;
    while (n) {
        ini = 1, fin = 1e5;
        while (ini <= fin) {
            m = (ini + fin) / 2;

            if (posible(n, m)) {
                ans = m;
                ini = m + 1;
            }
            else fin = m - 1;
        }
        if (n > necesario(ans)) ++ans;
        cout << ans << '\n';
        cin >> n;
    }

    return 0;
}