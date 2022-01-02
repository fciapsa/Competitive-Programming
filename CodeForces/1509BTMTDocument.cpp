#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, ts, ms, n;
    bool ok;
    string s;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> s;
        ts = 0;
        ms = 0;
        ok = true;
        for (int i = 0; i < n && ok; ++i) {
            if (s[i] == 'T') ++ts;
            else {
                ++ms;
                if (ms > ts) ok = false;
            }

        }
        ts = 0;
        ms = 0;
        for (int i = n - 1; i >= 0 && ok; --i) {
            if (s[i] == 'T') ++ts;
            else {
                ++ms;
                if (ms > ts) ok = false;
            }
        }
        

        if (ts != 2 * ms) ok = false;
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}