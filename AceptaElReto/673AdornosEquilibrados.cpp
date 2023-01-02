#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, c, best_ini, best_sum;
    cin >> n >> c;
    while (cin) {
        vector<int> v(n+1);
        for (int i = 1; i <= n; ++i) cin >> v[i];

        vector<int> accum(n+1, 0);
        for (int i = 1; i <= n; ++i) accum[i] = accum[i - 1] + v[i];

        best_ini = best_sum = 0;
        for (int i = 1; i <= n - c + 1; ++i) {
            ll sum = accum[i + c - 1] - accum[i - 1];
            if (sum % 2 == 0 && sum > best_sum) {
                bool found = binary_search(accum.begin(), accum.end(), accum[i - 1] + sum / 2);
                if (found) {
                    best_sum = sum;
                    best_ini = i;
                }
            }
        }

        if (best_ini) cout << best_ini << '\n';
        else cout << "SIN ADORNOS\n";

        cin >> n >> c;
    }

    return 0;
}