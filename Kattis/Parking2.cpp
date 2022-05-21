#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, x, mx, mn;
    cin >> tc;
    while (tc--) {
        cin >> n;
        mn = 100;
        mx = 0;
        while (n--) {
            cin >> x;
            if (x > mx) mx = x;
            if (x < mn) mn = x;
        }
        cout << 2 * (mx - mn) << '\n';
    }
    return 0;
}