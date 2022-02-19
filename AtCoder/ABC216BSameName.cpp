#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s, t;
    map<string, map<string, int>> mp;
    int n;
    bool found = false;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s >> t;
        if (++mp[s][t] > 1) found = true;
    }
    if (found) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}