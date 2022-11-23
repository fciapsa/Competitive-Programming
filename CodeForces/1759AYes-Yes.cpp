#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    string s;
    cin >> tc;
    while (tc--) {
        cin >> s;
        bool ok = s[0] == 'Y' || s[0] == 'e' || s[0] == 's';
        char prev = s[0];
        for (int i = 1; i < s.size() && ok; ++i) {
            if (prev == 'Y') ok = s[i] == 'e';
            else if (prev == 'e') ok = s[i] == 's';
            else ok = s[i] == 'Y';
            prev = s[i];
        }
        
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}