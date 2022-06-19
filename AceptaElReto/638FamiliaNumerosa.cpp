#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, c, n, mn, mx;
    cin >> tc;
    while (tc--) {
        cin >> c >> n;
        mn = mx = -1;
        for (int i = n; ; ++i) {
            if (i - i / c == n) {
                if (mn == -1) mn = mx = i;
                else mx = i;
            }
            else if (i - i / c > n) break;
        }

        cout << mn << ' ' << mx << '\n';
    }

    return 0;
}