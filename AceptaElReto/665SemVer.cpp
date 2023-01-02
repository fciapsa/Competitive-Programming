#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, x1, x2, x3, y1, y2, y3;
    char c;
    cin >> tc;
    while (tc--) {
        cin >> x1 >> c >> x2 >> c >> x3 >> y1 >> c >> y2 >> c >> y3;
        if (x1 != y1) {
            if (y1 == x1 + 1 && y2 == 0 && y3 == 0) cout << "SI\n";
            else cout << "NO\n";
        }
        else {
            if (x2 != y2) {
                if (y2 == x2 + 1 && y3 == 0) cout << "SI\n";
                else cout << "NO\n";
            }
            else {
                if (y3 == x3 + 1) cout << "SI\n";
                else cout << "NO\n";
            }
        }
    }

    return 0;
}