#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int x, c1, c2, c3, c4;
    cin >> x;
    while(x){
        vector<int> need(10, 0), have(10, 0);
        c1 = x % 10;
        x /= 10;
        c2 = x % 10;
        x /= 10;
        c3 = x % 10;
        x /= 10;
        c4 = x % 10;
        for (int i = 0; i < 10; ++i) {
            cin >> have[i];
        }

        ++need[c1];
        ++need[c2];
        ++need[c3];
        ++need[c4];
        int ans = 1e9;
        for (int i = 0; i < 10; ++i) {
            if (need[i]) {
                need[i] *= 3;
                ans = min(ans, have[i] / need[i]);
            }
        }
        cout << ans << '\n';
        cin >> x;
    }

    return 0;
}