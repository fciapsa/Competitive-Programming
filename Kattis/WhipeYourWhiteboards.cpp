#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll eea(ll a, ll b, ll& x, ll& y) {
    ll xx = y = 0, yy = x = 1;
    while (b) {
        ll q = a / b, t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    ll a, b, x, y, d, gcd, k, d1, d2;
    cin >> tc;
    while (tc--) {
        cin >> a >> b >> d;
        gcd = eea(a, -b, x, y);
        y = (-y);
        k = d / gcd;
        x *= k;
        y *= k;
        d1 = -b / gcd;
        d2 = a / gcd;
        while (y <= 0) {
            x += d1;
            y += d2;
        }
        while(x <= 0){
            x += d1;
            y += d2;
        }

        while (x - d1 > 0 && y-d2 > 0) {
            x -= d1;
            y -= d2;
        }

        cout << x << ' ' << y << '\n';
    }

    return 0;
}