#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    string s;
    cin >> tc;
    getline(cin, s);
    while (tc--) {
        getline(cin, s);
        stringstream ss(s);
        string ans = "";
        while (ss >> s) {
            if (isupper(s[0]))
                ans.push_back(s[0]);
        }
        cout << ans << '\n';
    }

    return 0;
}