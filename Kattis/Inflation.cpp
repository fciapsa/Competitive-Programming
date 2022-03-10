#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    double ans = 1;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 1; i <= n && ans != -1; ++i) {
        if (v[i-1] > i) ans = -1;
        else ans = fmin(ans, (double)v[i-1] / i);
    }

    if (ans == -1) cout << "impossible\n";
    else cout << fixed << setprecision(7) << ans << '\n';

    return 0;
}