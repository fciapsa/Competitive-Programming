#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, gap;
    cin >> tc;
    while (tc--) {
        cin >> n >> gap;
        vector<ll> val(n);
        for (int i = 0; i < n; ++i) cin >> val[i];

        for (int i = 1; i < n && i <= gap; ++i) val[i] = max(val[i], val[i - 1]);

        for (int i = gap + 1; i < n; ++i) {
            val[i] = max(val[i] + val[i - gap - 1], val[i - 1]);
        }

        cout << val[n - 1] << '\n';
    }

    return 0;
}