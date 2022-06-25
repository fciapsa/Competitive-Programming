#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll k, n, accum, ans, x;
    cin >> k >> n;
    while (k) {
        accum = 0;
        deque<int> dq;
        for (int i = 0; i < k; ++i) {
            cin >> x;
            dq.push_back(x);
            accum += x;
        }

        ans = accum;
        for (int i = k; i < n; ++i) {
            cin >> x;
            accum -= dq.front();
            dq.pop_front();
            accum += x;
            dq.push_back(x);
            if (accum > ans) ans = accum;
        }
        cout << ans << '\n';

        cin >> k >> n;
    }

    return 0;
}