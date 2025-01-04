#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll mygcd(ll a, ll b) {
    if (b == 0) return a;
    return mygcd(b, a % b);
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    ll a, b, g;
    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        g = mygcd(a, b);
        cout << (a / g + b / g) - 1 << '\n';
    }

    return 0;
}