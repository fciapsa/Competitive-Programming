#include <bits/stdc++.h>

using namespace std;
#define ll long long

/*1. If none, buy a coffee as fast as possible
* 2. Drink it all or buy another cup at the very last cart before there's no more coffee
*/

int main() {
    std::ios::sync_with_stdio(false);
    ll l, a, b, t, r;
    int n;
    cin >> l >> a >> b >> t >> r >> n;
    ll cd = a * t, fast = b * r;
    ll tot = cd + fast;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    if(n == 0 || v[n - 1] != l) {
        ++n;
        v.push_back(l);
    }

    vector<double> dp(n, 0.0);//dp[n-1] = 0.0
    vector<int> opts(n);
    for (int j = n - 2; j >= 0; --j) {
        int nx1, nx2;
        double opt1, opt2;
        nx1 = lower_bound(v.begin(), v.end(), v[j] + tot) - v.begin();
        if (nx1 == n) {
            if (l - v[j] <= cd) opt1 = (l - v[j]) / (double)a;
            else opt1 = t + (l - v[j] - cd) / (double)b;
        }
        else opt1 = t + r + (v[nx1] - v[j] - tot) / (double)a + dp[nx1];


        nx2 = nx1 - 1;
        if (nx2 > j) {
            if (v[nx2] - v[j] <= cd) opt2 = (v[nx2] - v[j]) / (double)a + dp[nx2];
            else opt2 = t + (v[nx2] - v[j] - cd) / (double)b + dp[nx2];
        }
        else opt2 = 1e15;

        if (opt1 <= opt2) {
            dp[j] = opt1;
            opts[j] = 1;
        }
        else {
            dp[j] = opt2;
            opts[j] = 2;
        }
    }

    int ans = 0;
    vector<int> v_ans;
    int k = 0;
    while (k < n - 1) {
        ++ans;
        v_ans.push_back(k);
        if(opts[k] == 1) k = lower_bound(v.begin(), v.end(), v[k] + tot) - v.begin();
        else k = (lower_bound(v.begin(), v.end(), v[k] + tot) - v.begin()) - 1;
    }

    cout << ans << '\n';
    if (ans) {
        cout << v_ans[0];
        for (int i = 1; i < ans; ++i) cout << ' ' << v_ans[i];
        cout << '\n';
    }

    return 0;
}