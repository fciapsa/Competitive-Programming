#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll tc, n, k;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.end());

        vector<ll> accum(n);
        accum[0] = v[0];
        for (int i = 1; i < n; ++i) accum[i] = v[i] + accum[i - 1];

        ll ans = accum[n - 1 - k];
        for (int i = 1; i < 2 * k; i += 2) {
            ans = max(ans, accum[n - k + i / 2] - accum[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}