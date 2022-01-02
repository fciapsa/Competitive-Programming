#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    ll tc, n, sol;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<ll> v(n+2);
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }

        sol = 0;
        for (int i = 1; i <= n; ++i) {
            if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
                sol += (v[i] - max(v[i - 1], v[i + 1]));
                v[i] = max(v[i - 1], v[i + 1]);
            }
        }

        for (int i = 0; i < v.size() - 1; ++i) {
            sol += abs(v[i] - v[i + 1]);
        }
        cout << sol << '\n';
    }

return 0;
}