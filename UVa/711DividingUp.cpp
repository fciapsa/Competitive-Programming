#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define N 6

int main() {
    std::ios::sync_with_stdio(false);
    int k = 1;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    while (v[0] || v[1] || v[2] || v[3] || v[4] || v[5]) {
        int sum = 0;
        for (int i = 0; i < N; ++i) sum += (i + 1) * v[i];

        /* This is not the intended solution to this problem.
           The intended solution is to reduce the numbers by mathematical reasoning and solve for small number of marbles.
           However, this DP solution puts in evidence a smart way of calculating the least possible amount of values.
        */
        vector<int> dp(sum / 2 + 1, 0);
        if (sum % 2 == 0) {
            for (int i = 0; i <= min(v[0],sum/2); ++i) dp[i] = 1;

            for (int i = 1; i < N; ++i) {
                for (int j = sum / 2; j >= 0; --j) {
                    if (dp[j] == 0) continue;

                    for (int k = 0; k <= v[i]; ++k) {
                        int x = j + k * (i + 1);
                        if (x > sum / 2) break;
                        if (dp[x] == i+1) break;
                        dp[x] = i+1;
                    }
                }
            }
        }
        
        cout << "Collection #" << k++ << ":\n";
        cout << "Can";
        if (!dp[sum/2]) cout << "\'t";
        cout << " be divided.\n\n";
        for (int i = 0; i < N; ++i) cin >> v[i];
    }

    return 0;
}