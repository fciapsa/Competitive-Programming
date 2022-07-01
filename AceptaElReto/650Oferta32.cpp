#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, ans;
    cin >> n;
    while (cin) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(v.rbegin(), v.rend());

        ans = 0;
        for (int i = 2; i < n; i += 3) ans += v[i];
        cout << ans << '\n';

        cin >> n;
    }

    return 0;
}