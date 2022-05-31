#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    string s1, s2;
    cin >> tc;
    while (tc--) {
        cin >> s1 >> s2;
        cout << s1 << '\n' << s2 << '\n';
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) cout << '.';
            else cout << '*';
        }
        cout << "\n\n";
    }

    return 0;
}