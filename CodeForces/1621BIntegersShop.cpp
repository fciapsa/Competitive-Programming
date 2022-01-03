#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll tc, n, a, b, c, mn, mx, mn_c, mx_c, max_len, max_len_c;
    cin >> tc;
    while (tc--) {
        cin >> n;

        mn = 1e9 + 1;
        mx = max_len = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b >> c;
            if (a < mn) {
                mn = a;
                mn_c = c;
            }
            else if (a == mn && c < mn_c) mn_c = c;

            if (b > mx) {
                mx = b;
                mx_c = c;
            }
            else if (b == mx && c < mx_c) mx_c = c;

            if (b - a + 1 > max_len) {
                max_len = b - a + 1;
                max_len_c = c;
            }
            else if (b - a + 1 == max_len && c < max_len_c) max_len_c = c;

            if (mx - mn + 1 == max_len) cout << min(max_len_c, mn_c+mx_c) << '\n';
            else cout << mn_c + mx_c << '\n';
        }
    }
    return 0;
}