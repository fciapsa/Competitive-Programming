#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    ll x, mx, accum;
    cin >> n;
    while (cin) {
        accum = mx = 0;
        while (n--) {
            cin >> x;
            accum += x;
            if (x > mx) mx = x;
        }

        cout << max(accum, 2*mx) << '\n';

        cin >> n;
    }

    return 0;
}