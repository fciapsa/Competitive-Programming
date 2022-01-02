#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

const int MOD = 1000000007;

int modPot2(int e) {
    if (e == 0) return 1;
    if (e == 1) return 2;

    ll aux = modPot2(e / 2);
    if (e % 2) return (((aux * aux) % MOD) * 2) % MOD;
    else return (aux * aux) % MOD;
}

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, x, cc, act;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> v1(n), v2(n);
        vector<int> pair(n+1);

        for (int i = 0; i < n; ++i) cin >> v1[i];
        for (int i = 0; i < n; ++i) cin >> v2[i];

        for (int i = 0; i < n; ++i) {
            pair[v1[i]] = v2[i];
        }

        cc = 0;
        vector<bool> visited(n+1, false);
        for (int i = 0; i < n; ++i) {
            act = v1[i];
            if (!visited[act]) {
                while (!visited[act]) {
                    visited[act] = true;
                    act = pair[act];
                }
                ++cc;
            }
        }

        cout << modPot2(cc) << '\n';
    }

    return 0;
}