#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, x, ans, ind;
    cin >> n;
    while (n) {
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;

        ans = ind =  0;
        cin >> x;
        while (x) {
            while (ind < n && v[ind].second < x) {
                ++ind;
            }
            if (ind < n && v[ind].first > x) ++ans;
            else if (ind == n) ++ans;
            cin >> x;
        }

        cout << ans << '\n';
        cin >> n;
    }

    return 0;
}