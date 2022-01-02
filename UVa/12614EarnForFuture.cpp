#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, x, ans, k = 1;
    cin >> tc;
    while (tc--) {
        cin >> n;
        ans = -1;
        while (n--) {
            cin >> x;
            if (x > ans) ans = x;
        }
        cout << "Case " << k++ << ": " << ans << '\n';    
    }

    return 0;
}