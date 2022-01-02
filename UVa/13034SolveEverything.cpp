#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int s, x;
    bool ok;
    cin >> s;
    for (int i = 1; i <= s; ++i) {
        ok = true;
        for (int j = 0; j < 13; ++j) {
            cin >> x;
            ok = ok && x;
        }
        cout << "Set #" << i << ": ";
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}