#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, x;
    string s;
    bool ok = true;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        if (s[0] != 'm') {
            x = stoi(s);
            if (x != i) ok = false;
        }
    }
    if (ok) cout << "makes sense\n";
    else cout << "something is fishy\n";
    return 0;
}