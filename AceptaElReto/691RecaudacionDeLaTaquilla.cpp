#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int f, a, c, x;
    ll ans = 0;
    cin >> f;
    while (cin) {
        cin >> a >> c;
        priority_queue<int> pq;
        for (int i = 0; i < f; ++i) {
            cin >> x;
            if (x < a) pq.push(a - x);
        }

        ans = 0;
        while (c && pq.size()) {
            ans += pq.top();
            if (pq.top() > 1) pq.push(pq.top() - 1);
            pq.pop();
            --c;
        }
        cout << ans << '\n';

        cin >> f;
    }

    return 0;
}