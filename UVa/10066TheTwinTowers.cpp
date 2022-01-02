#include <bits/stdc++.h>

using namespace std;
#define ll long long

int rellenar(int i, int j, vector<vector<int>>& dp, vector<int> const&v1, vector<int> const&v2) {
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int opt1 = -1, opt2, opt3;
    if (v1[i] == v2[j]) opt1 = 1 + rellenar(i - 1, j - 1, dp, v1, v2);
    opt2 = rellenar(i - 1, j, dp, v1, v2);
    opt3 = rellenar(i, j - 1, dp, v1, v2);

    return dp[i][j] = max(opt1, max(opt2, opt3));
}

int main() {
    std::ios::sync_with_stdio(false);
    int n1, n2, x, k = 1;
    cin >> n1 >> n2;
    while (n1 != 0) {
        vector<int> v1(n1), v2(n2);
        for (int i = 0; i < n1; ++i) cin >> v1[i];
        for (int i = 0; i < n2; ++i) cin >> v2[i];

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        cout << "Twin Towers #" << k++ << '\n';
        cout << "Number of Tiles : " << rellenar(n1 - 1, n2 - 1, dp, v1, v2) << "\n\n";

        cin >> n1 >> n2;
    }
    return 0;
}