#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, s, t1, t2, ans;
    cin >> n;
    while (n != -1) {
        cin >> s >> t1;
        ans = s * t1;
        for (int i = 1; i < n; ++i) {
            cin >> s >> t2;
            ans += s * (t2 - t1);
            t1 = t2;
        }
        cout << ans << " miles\n";
    cin >> n;
    }
return 0;
}