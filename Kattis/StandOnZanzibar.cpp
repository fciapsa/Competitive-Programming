#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll tc, x1, x2, ans;
    cin >> tc;
    while (tc--) {
        cin >> x1 >> x2;
        ans = 0;
        while (x2 != 0) {
            ans += max((ll)0, x2 - 2 * x1);
            x1 = x2;
            cin >> x2;
        }
        cout << ans << '\n';
    }
    return 0;
}