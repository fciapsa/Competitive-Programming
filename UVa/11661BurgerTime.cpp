#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int l, d, r, mn;
    string s;
    cin >> l;
    while (l != 0) {
        cin >> s;
        if (s.find('Z') != string::npos) cout << "0\n";
        else {
            d = r = -1;
            mn = 1e9;
            for (int i = 0; i < l; ++i) {
                if (s[i] == 'D') d = i;
                else if (s[i] == 'R') r = i;
                if (r != -1 && d != -1) mn = min(mn, abs(d - r));
            }
            cout << mn << '\n';
        }
        cin >> l;
    }

    return 0;
}