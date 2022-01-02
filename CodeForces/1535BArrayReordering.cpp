#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

/*This solution has redundant code. The order of odd elements doesn't matter, because in that case gcd(a_i, 2a_j) = gcd(a_i,a_j) */

struct par {
    int x, prio;
    bool operator<(par const& other) const{
        return prio > other.prio;
    }
};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n;
    ll sol;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<par> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].x;

        for (int i = 0; i < n; ++i) {
            if (v[i].x % 2) {
                for (int j = 0; j < n; ++j) {
                    if (j != i && v[j].x % 2 && gcd(v[i].x, v[j].x) > 1) ++v[i].prio;
                }
            }
            else v[i].prio = n-1;
        }

        sort(v.begin(), v.end());
        sol = 0;
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            if (v[i].x % 2) {
                for (int j = i + 1; j < n; ++j) {
                    if (gcd(v[i].x, v[j].x) > 1) ++sol;
                }
            }
            else sol += j;
        }
        cout << sol << '\n';
    }

return 0;
}