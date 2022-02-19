#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define ll long long
using namespace std;

ll mod;

ll potMod(ll base, ll pot) {
    if (pot == 0) return 1 % mod;
    if (pot == 1) return base % mod;

    ll m = pot / 2;
    ll aux = potMod(base, m);
    if (pot % 2) return (((aux * aux) % mod) * base) % mod;
    else return (aux * aux) % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    mod = m * m;
    cout << (potMod(10, n) / m) % m;

return 0;
}