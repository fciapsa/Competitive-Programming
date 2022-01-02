#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, x;
    cin >> tc;
    while (tc--) {
        cin >> n;
        map<int, int> previous;
        vector<ll> maxUntil(n);
        maxUntil[0] = 0;
        cin >> x;
        previous[x] = 0;

        for (int i = 1; i < n; ++i) {
            cin >> x;
            if (previous.count(x)) maxUntil[i] = max(1 + maxUntil[previous[x]], maxUntil[i - 1]);
            else maxUntil[i] = maxUntil[i - 1];
            previous[x] = i;
        }

        cout << maxUntil[n - 1] << '\n';
    }
    return 0;
}