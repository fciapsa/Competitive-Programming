#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, k1, k2, w, b, sw, sb;
    cin >> tc;
    while (tc--) {
        cin >> n >> k1 >> k2 >> w >> b;
        sw = 0;
        sb = 0;
        if (k1 <= k2) {
            sw = k1;
            sw += (k2-k1) / 2;
            sb = n - k2;
            sb += (k2 - k1) / 2;
        }
        else {
            sw = k2;
            sw += (k1 - k2) / 2;
            sb = n - k1;
            sb += (k1 - k2) / 2;
        }

        if (sw >= w && sb >= b) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}