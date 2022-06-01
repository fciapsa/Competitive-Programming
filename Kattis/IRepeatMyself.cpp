#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    string s, p;
    bool ok;
    cin >> tc;
    getline(cin, s);
    while (tc--) {
        getline(cin, s);
        for (int i = 1; i <= s.size(); ++i) {
            p = s.substr(0, i);
            ok = true;
            for (int j = 0; j < s.size() && ok; ++j) ok = s[j] == p[j % i];
            if (ok) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}