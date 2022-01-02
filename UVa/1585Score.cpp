#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, ans, acc;
    string s;
    cin >> tc;
    while (tc--) {
        ans = 0;
        acc = 0;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'O') {
                ++acc;
                ans += acc;
            }
            else acc = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}