#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    ll ans, act;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        ans = 0;
        act = 10;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '.') act = 10;
            else {
                ans += act;
                act += 10;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}