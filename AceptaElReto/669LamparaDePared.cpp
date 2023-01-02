#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, x;
    cin >> n;
    while (n) {
        unordered_map<int, int> mp;
        int g4 = 0, g2 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            ++mp[x];
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            while (it->second >= 4) {
                ++g4;
                it->second -= 4;
            }
            if (it->second >= 2) ++g2;
        }

        int ans = 0;
        while (true) {
            if (g4 && g2) {
                ++ans;
                --g4;
                --g2;
            }
            else if (g4) {
                g2 += 2;
                --g4;
            }
            else break;
        }
        cout << ans << '\n';
        cin >> n;
    }

    return 0;
}