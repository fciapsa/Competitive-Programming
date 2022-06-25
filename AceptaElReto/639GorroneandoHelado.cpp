#include <bits/stdc++.h>

using namespace std;
#define ll long long

int score(int r1, int r2, int r3) {
    return max(max(r1, r2), r3) - min(min(r1, r2), r3);
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, tot;
    cin >> n;
    while (cin) {
        tot = 0;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            tot += v[i];
        }

        int r1 = v[0], r2 = tot - v[0] - v[n - 1], r3 = v[n - 1], nextr1, nextr3;
        int ans = score(r1, r2, r3);
        int i1 = 1, i2 = n - 2;
        while (i1 < i2) {
            nextr1 = r1 + v[i1];
            nextr3 = r3 + v[i2];
            ans = min(ans, score(nextr1, r2 - v[i1], r3));
            ans = min(ans, score(r1, r2 - v[i2], nextr3));
            if (nextr1 < nextr3) {
                r1 = nextr1;
                r2 -= v[i1];
                ++i1;
            }
            else {
                r3 = nextr3;
                r2 -= v[i2];
                --i2;
            }
        }

        cout << ans << '\n';
        cin >> n;
    }

    return 0;
}