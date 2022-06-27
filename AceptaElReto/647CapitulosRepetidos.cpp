#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, x, ans, ind, act;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        ans = act = 0;
        ind = 0;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            if (s.count(v[i])) {
                while (s.count(v[i])) {
                    s.erase(v[ind]);
                    ++ind;
                    --act;
                }
            }

            s.insert(v[i]);
            ++act;
            if (act > ans) ans = act;
        }

        cout << ans << '\n';
    }

    return 0;
}