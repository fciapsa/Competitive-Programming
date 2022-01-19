#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll tc, n, sol, act, l;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<ll> k(n), h(n), diff_min(n);
        for (int i = 0; i < n; ++i) cin >> k[i];
        for (int i = 0; i < n; ++i) cin >> h[i];

        diff_min[n - 1] = k[n - 1] - h[n - 1];
        for (int i = n - 2; i >= 0; --i) diff_min[i] = min(diff_min[i + 1], k[i] - h[i]);

        act = k[0] - diff_min[0];//h[0] + k[0] - h[0] - diff_min[0]
        sol = (act * (1 + act)) / 2;

        for (int i = 1; i < n; ++i) {
            l = k[i] - k[i - 1];

            if (l >= k[i] - diff_min[i]) {
                act = k[i] - diff_min[i];
                sol += (act * (1 + act)) / 2;
            }
            else {
                sol += (l * (act + 1 + act + l)) / 2;
                act += l;
            }
        }

        cout << sol << '\n';
    }

    return 0;
}