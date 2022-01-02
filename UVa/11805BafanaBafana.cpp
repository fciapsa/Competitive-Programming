#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, k, p, caso = 1, ans;
    cin >> tc;
    while (tc--) {
        cin >> n >> k >> p;
        if ((k + p) % n) ans = (k + p) % n;
        else ans = n;
        cout << "Case " << caso << ": " << ans << '\n';
        ++caso;
    }
    return 0;
}