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
        cout << s;
        for (int i = s.size() - 1; i >= 0; --i) cout << s[i];
        cout << '\n';
    }

    return 0;
}