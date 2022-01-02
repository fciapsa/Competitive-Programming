#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    ll p, r, f, ans;
    cin >> tc;
    while (tc--) {
        cin >> p >> r >> f;
        ans = 0;
        while (p <= f) {
            ++ans;
            p *= r;
        }
        cout << ans << '\n';
    }
    return 0;
}