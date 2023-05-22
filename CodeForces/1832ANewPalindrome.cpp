#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    string s;
    while (tc--) {
        cin >> s;
        map<char, int> mp;
        for (int i = 0; i < s.size(); ++i) {
            ++mp[s[i]];
        }

        int geq2 = 0;
        for (auto kv : mp) {
            if (kv.second >= 2) ++geq2;
        }
        if (geq2 >= 2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}