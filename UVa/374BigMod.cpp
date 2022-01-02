#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll m;

ll potMod(ll b, ll p) {
    if (p == 0) return 1 % m;
    if (p == 1) return b % m;

    ll aux = potMod(b, p / 2);
    if (p % 2) return (((aux * aux) % m) * b) % m;
    return (aux * aux) % m;
}

int main() {
    std::ios::sync_with_stdio(false);
    ll b, p;
    cin >> b >> p >> m;
    while (cin) {
        cout << potMod(b, p) << '\n';
        cin >> b >> p >> m;
    }
    return 0;
}