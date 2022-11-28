#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, x;
    cin >> tc;
    while (tc--) {
        cin >> n >> x;
        if (n % x == 0) {
            vector<int> ans(n + 1);
            ans[1] = x;
            ans[n] = 1;
            for (int i = 2; i < n; ++i) ans[i] = i;
            if (x != n) ans[x] = n;

            int try_to_decrease = x;
            for (int i = 2; i < n; ++i) {
                if (ans[i] % try_to_decrease == 0 && ans[try_to_decrease] % i == 0) {
                    swap(ans[i], ans[try_to_decrease]);
                    try_to_decrease = i;
                }
            }

            cout << ans[1];
            for (int i = 2; i <= n; ++i) cout << ' ' << ans[i];
            cout << '\n';
        }
        else cout << "-1\n";
    }

    return 0;
}