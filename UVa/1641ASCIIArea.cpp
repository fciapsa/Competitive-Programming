#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int h, w, ans;
    string s;

    cin >> h >> w;
    while (cin) {
        ans = 0;
        while (h--) {
            bool in = false;
            cin >> s;
            for (int i = 0; i < w; ++i) {
                if (in) {
                    ++ans;
                    if (s[i] != '.') in = false;
                }
                else if (s[i] != '.') in = true;
            }
        }
        cout << ans << '\n';
        cin >> h >> w;
    }
    return 0;
}