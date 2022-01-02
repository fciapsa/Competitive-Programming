#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    double q, t, ans = 0;
    cin >> n;
    while (n--) {
        cin >> q >> t;
        ans += q * t;
    }
    cout << ans << '\n';
    return 0;
}