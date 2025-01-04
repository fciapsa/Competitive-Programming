#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    ll prev, act, mx, ans;
    cin >> n;
    while (n) {
        cin >> prev;
        mx = prev;
        ans = 1;

        for (int i = 1; i < n; ++i) {
            cin >> act;
            if (act >= mx) {
                mx = act;
                ++ans;
            }
            else ans = 0;
        }
        cout << ans << '\n';
        cin >> n;
    }

    return 0;
}