#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, mn, ans;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        mn = v[n-1];
        ans = -1e9;
        for (int i = n - 2; i >= 0; --i) {
            ans = max(v[i] - mn, ans);
            mn = min(v[i], mn);
        }

        cout << ans << '\n';
    }
    return 0;
}