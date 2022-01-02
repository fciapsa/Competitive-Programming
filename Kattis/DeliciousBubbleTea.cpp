#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, k, x, mn = 1e9;
    cin >> n;
    vector<int> teas(n+1);
    for (int i = 1; i <= n; ++i) cin >> teas[i];
    
    cin >> m;
    vector<int> tops(m+1);
    for (int i = 1; i <= m; ++i) cin >> tops[i];

    for (int i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> x;
            if (teas[i] + tops[x] < mn) mn = teas[i] + tops[x];
        }
    }
    cin >> x;

    cout << max((x - mn) / mn, 0) << '\n';

    return 0;
}