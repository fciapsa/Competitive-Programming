#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, b, h, w, mn = 1e9, p, a;
    cin >> n >> b >> h >> w;
    while (h--) {
        cin >> p;
        for (int i = 0; i < w; ++i) {
            cin >> a;
            if (a >= n && p * n < min(mn,b) ) mn = p * n;
        }
    }
    if (mn == 1e9) cout << "stay home\n";
    else cout << mn << '\n';
    return 0;
}