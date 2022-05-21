#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    int ans = 0, x1 = 0, x2 = 0;
    bool second = false;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ';') {
            if (x2 != 0) ans += x2 - x1 + 1;
            else ++ans;
            x1 = x2 = 0;
            second = false;
        }
        else if (s[i] == '-') second = true;
        else {
            if (second) {
                x2 *= 10;
                x2 += int(s[i]) - int('0');
            }
            else {
                x1 *= 10;
                x1 += int(s[i]) - int('0');
            }
        }
    }
    if (x2 != 0) ans += x2 - x1 + 1;
    else ++ans;
    cout << ans << '\n';
    return 0;
}