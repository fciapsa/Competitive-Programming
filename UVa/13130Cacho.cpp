#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    bool ok;
    vector<int> v(5);
    cin >> tc;
    while (tc--) {
        for (int i = 0; i < 5; ++i) {
            cin >> v[i];
        }
        ok = true;
        for (int i = 1; i < 5 && ok; ++i) {
            ok = v[i] == v[i - 1] + 1;
        }
        if (ok) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}