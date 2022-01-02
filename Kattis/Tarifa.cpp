#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll x, n, ans;
    cin >> x >> n;
    ans = (n+1) * x;
    while (n--) {
        cin >> x;
        ans -= x;
    }
    cout << ans << '\n';
    return 0;
}