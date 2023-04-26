#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    ll ans, last;
    cin >> n;
    while (cin) {
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(v.rbegin(), v.rend());

        last = ans = v[0];
        for (int i = 1; i < n && last > 1; ++i) {
            if (v[i] >= last) --last;
            else last = v[i];
            ans += last;
        }
        cout << ans << '\n';
        cin >> n;
    }

    return 0;
}