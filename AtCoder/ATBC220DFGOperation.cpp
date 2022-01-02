#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<vector<int>> formas(n, vector<int>(10));
    formas[0][v[0]] = 1;
    int res;
    for (int etapa = 0; etapa < n - 1; ++etapa) {
        for (int i = 0; i < 10; ++i) {
            if (formas[etapa][i] > 0) {
                res = (i + v[etapa + 1]) % 10;
                formas[etapa + 1][res] = (formas[etapa + 1][res] + formas[etapa][i]) % MOD;

                res = (i * v[etapa + 1]) % 10;
                formas[etapa + 1][res] = (formas[etapa + 1][res] + formas[etapa][i]) % MOD;
            }
        }
    }

    for (int i = 0; i < 10; ++i) cout << formas[n-1][i] << '\n';

    return 0;
}