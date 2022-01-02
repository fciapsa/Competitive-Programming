#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, r, k, ans;
    cin >> n >> r >> k;
    ans = k + abs(k - r);
    if (ans >= n) cout << ans + r << '\n';
    else {
        if ((n - ans) % 2) cout << ans + (n - ans) + 1 + r << '\n';
        else cout << ans + (n - ans) + r << '\n';
    }
    return 0;
}