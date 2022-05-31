#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n;
    bool pre;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.end());

        pre = false;
        for (int i = 0; i < n - 1 && !pre; ++i) {
            if (v[i].length() < v[i + 1].length() && v[i + 1].substr(0,v[i].length()) == v[i])
                pre = true;
        }

        if (pre) cout << "NO\n";
        else cout << "YES\n";
    }

return 0;
}