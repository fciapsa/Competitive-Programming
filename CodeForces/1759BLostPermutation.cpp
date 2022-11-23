#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, m, s, sum_missing;
    cin >> tc;
    while (tc--) {
        cin >> m >> s;
        vector<int> v(m);
        for (int i = 0; i < m; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        sum_missing = 0;
        for (int i = 1; i < v[0]; ++i) {
            sum_missing += i;
        }
        for (int i = 1; i < v.size(); ++i) {
            for (int j = v[i - 1] + 1; j < v[i]; ++j) {
                sum_missing += j;
            }
        }

        for (int i = v[v.size() - 1] + 1; sum_missing < s; ++i) {
            sum_missing += i;
        }

        if (sum_missing == s) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}