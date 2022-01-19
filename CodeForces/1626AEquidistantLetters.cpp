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
        sort(s.begin(), s.end());
        cout << s << '\n';
    }

return 0;
}