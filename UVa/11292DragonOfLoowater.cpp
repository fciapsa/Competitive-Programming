#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, i, j, cost;
    cin >> n >> m;
    while (n != 0) {
        vector<int> h(n), k(m);
        for (int i = 0; i < n; ++i) cin >> h[i];
        for (int i = 0; i < m; ++i) cin >> k[i];

        sort(h.begin(), h.end());
        sort(k.begin(), k.end());

        cost = i = j = 0;
        while (i < n && j < m) {
            while (j < m && k[j] < h[i]) ++j;
            
            if (j < m) {
                cost += k[j];
                ++i;
                ++j;
                
            }
        }

        if (i == n) cout << cost << '\n';
        else cout << "Loowater is doomed!\n";

        cin >> n >> m;
    }

    return 0;
}