#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, k, x, ans;
    cin >> n;
    while (n--) {
        cin >> k;
        ans = 1;
        while (k--) {
            cin >> x;
            ans += x - 1;
        }
        cout << ans << '\n';
    }

    return 0;
}