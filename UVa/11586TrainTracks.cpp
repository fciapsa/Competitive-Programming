#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, m, f;
    stringstream ss;
    string s;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        m = f = 0;
        getline(cin, s);
        ss.clear();
        ss << s;

        ss >> s;
        while (!ss.eof()) {
            if (s[0] == 'M') ++m;
            else ++f;
            if (s[1] == 'M') ++m;
            else ++f;
            ss >> s;
        }
        if (s[0] == 'M') ++m;
        else ++f;
        if (s[1] == 'M') ++m;
        else ++f;

        if (m + f == 2) cout << "NO LOOP\n";
        else {
            if (m == f) cout << "LOOP\n";
            else cout << "NO LOOP\n";
        }
    }
    return 0;
}