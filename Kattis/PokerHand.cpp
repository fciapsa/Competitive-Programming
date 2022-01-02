#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    map<char, int> mp;
    string s;
    for (int i = 0; i < 5; ++i) {
        cin >> s;
        ++mp[s[0]];
    }

    int ans = -1;
    for (auto cv : mp) {
        if (cv.second > ans) ans = cv.second;
    }
    cout << ans << '\n';
    return 0;
}