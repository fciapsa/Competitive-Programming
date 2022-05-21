#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, ans = 7;
    string s;
    cin >> n;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        if (s[5] == 'o') ans = min(ans + 1, 10);
        else ans = max(ans - 1, 0);
    }
    cout << ans << '\n';
    return 0;
}