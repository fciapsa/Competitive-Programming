#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct par {
    ll ind, val;
    bool operator<(par const& o) const {
        return val < o.val || (val == o.val && ind > o.ind);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    ll n, k, ans2;
    cin >> n >> k;
    while (n) {
        vector<ll> v(n);
        cin >> v[0];
        for (int i = 1; i < n; ++i) {
            cin >> v[i];
            v[i] += v[i - 1];
        }

        /*vector<ll> dp(n, 0);
        dp[k - 1] = v[k - 1];
        for (int i = k; i < n; ++i) {
            dp[i] = max(dp[i - 1], (v[i] - v[i - k]) + dp[i - k]);
        }*/

        priority_queue<par> pq;
        pq.push({ 0, v[k - 1] });
        for (int i = 1; i <= n - k; ++i) {
            pq.push({ i, v[i+k-1] - v[i - 1] });
        }

        vector<bool> avail(n, true);
        ans2 = 0;
        par act;
        while (!pq.empty()) {
            act = pq.top();
            pq.pop();

            if (avail[act.ind]) {
                ans2 += act.val;
                for (int i = act.ind; i < act.ind + k && i < n; ++i) avail[i] = false;
                for (int i = act.ind-1; i >= 0 && i > act.ind - k; --i) avail[i] = false;
            }
        }

        cout << v[n - 1] - ans2 << '\n';

        cin >> n >> k;
    }

    return 0;
}