#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, ans, flag, x;
    cin >> n >> m;
    while (cin) {
        ans = 0;
        while (n--) {
            flag = 1;
            for(int i = 0; i < m; ++i) {
                cin >> x;
                flag = flag && x;
            }
            if (flag)++ans;
        }
        cout << ans << '\n';

        cin >> n >> m;
    }
    return 0;
}