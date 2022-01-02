#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, x, k = 1, mn, mx;
    cin >> n;
    while (cin) {
        mn = 1000001;
        mx = -1000001;
        while (n--) {
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }

        cout << "Case " << k++ << ": " << mn << ' ' << mx << ' ' << mx - mn << '\n';

        cin >> n;
    }
    return 0;
}