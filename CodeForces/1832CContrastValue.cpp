#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll pend = 0, shifts = 2;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i - 1]) {
                if (pend == -1) ++shifts;
                pend = 1;
            }
            else if (a[i] < a[i - 1]) {
                if (pend == 1) ++shifts;
                pend = -1;
            }
        }

        if (pend == 0) cout << "1\n";
        else cout << shifts << '\n';
    }

    return 0;
}