#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

struct par {
    ll speed, cant;
};

int main() {
    std::ios::sync_with_stdio(false);

    ll n, a, b, act, cont, sol;
    cin >> n;
    vector<ll> sp(n);
    for (int i = 0; i < n; ++i) cin >> sp[i];
    sort(sp.begin(), sp.end());

    vector<par> v;
    a = 0;
    while(a < n) {
        act = sp[a];
        cont = 1;
        ++a;
        while (a < n && sp[a] == act) {
            ++cont;
            ++a;
        }

        v.push_back({ act, cont});
    }

    n = v.size();

    
    vector<vector<ll>> dpcant(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) dpcant[i][i] = v[i].cant;

    for (int d = 1; d < n; ++d) {
        for (int i = 0, j = i+d; i < n - d; ++i, ++j) {
            dpcant[i][j] = dpcant[i][j - 1] + v[j].cant;
        }
    }
    /*
    vector<vector<ll>> dpmax(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) dpmax[i][i] = v[i].speed;

    for (int d = 1; d < n; ++d) {
        for (int i = 0, j = i + d; i < n - d; ++i, ++j) {
            dpmax[i][j] = max(dpmax[i][j - 1], v[j].speed);
        }
    }
    */

    vector<vector<ll>> dp(n, vector<ll>(n));
    dp[0][n - 1] = 0;
    for (int j = n - 2; j >= 0; --j) dp[0][j] = dp[0][j + 1] + (v[j+1].speed - v[j].speed)*dpcant[j+1][n-1];
    for (int i = 1; i < n; ++i) dp[i][n - 1] = dp[i - 1][n - 1] + (v[i].speed - v[i-1].speed)*dpcant[0][i-1];

    for (int i = 1; i < n; ++i) {
        for (int j = n - 2; j >= 0; --j) {
            dp[i][j] = min(dp[i - 1][j] + (v[i].speed - v[i-1].speed)*(dpcant[0][i-1] + dpcant[j+1][n-1]) , 
                dp[i][j + 1] + (v[j+1].speed - v[j].speed)*(dpcant[0][i-1] + dpcant[j+1][n-1]));
        }
    }


    sol = dp[0][0];
    for (int i = 1; i < n; ++i) sol = min(sol, dp[i][i]);

    cout << sol << '\n';
    return 0;
}