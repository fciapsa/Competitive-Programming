#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> pots = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536,
                    131072, 262144, 524288, 1048576, 2097152, 4194304 };

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, sol, inv1, inv2, inv3;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        //precalculate closest value that can start a new category
        vector<int> start(n);
        start[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i - 1]) start[i] = i;
            else start[i] = start[i - 1];
        }

        sol = 2 + *lower_bound(pots.begin(), pots.end(), n) - n;//x >= than a[n-1] or y <= than a[0]
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) continue;
            //x = a[i]
            inv1 = *lower_bound(pots.begin(), pots.end(), i) - i;//invited to lightweight
            //iterate over size of middleweight
            for (int k = 0; k < pots.size(); ++k) {
                if (i + pots[k] >= n) {
                    inv2 = pots[k] - (n - i);
                    inv3 = 1;
                }
                else {
                    inv2 = pots[k] - (start[i + pots[k]] - i);
                    inv3 = *lower_bound(pots.begin(), pots.end(), n - start[i + pots[k]]) - (n - start[i+pots[k]]);
                }

                sol = min(sol, inv1 + inv2 + inv3);
            }
        }

        cout << sol << '\n';
    }

    return 0;
}