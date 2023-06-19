#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int c, r, ans, diag;
    char x;
    cin >> c >> r;
    while (c | r) {
        ans = 0;
        for (int i = 0; i < r; ++i) {
            diag = 0;
            for (int j = 0; j < c; ++j) {
                cin >> x;
                if (x == '\\' || x == '/') {
                    if (diag) diag = 0;
                    else {
                        diag = 1;
                        ++ans;
                    }
                }

                if (diag && x == '.') ++ans;             
            }
        }
        cout << ans << '\n';

        cin >> c >> r;
    }

    return 0;
}