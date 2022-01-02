#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, score, best_score, x;
    cin >> n >> m;
    while (cin) {
        vector<int> b(m);
        vector<int> sums(m);
        vector<int> d(m);
        score = best_score = 0;
       
        for (int i = 0; i < m; ++i) {
            cin >> b[i] >> d[i];
            sums[i] = d[i];
            for (int j = 1; j < n; ++j) {
                cin >> x;
                sums[i] += x;
            }
            if (sums[i] <= b[i]) score += d[i];
        }

        for (int i = 0; i < m; ++i) {
            sums[i] -= d[i];
            d[i] = -1;
            for (int j = 1; j <= 10000; j *= 10) {
                if (sums[i] + j <= b[i]) d[i] = j;
            }
            if (d[i] != -1) best_score += d[i];
        }

        cout << best_score - score << '\n';

        cin >> n >> m;
    }

    return 0;
}