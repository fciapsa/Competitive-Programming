#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <functional>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    ll tc, n, rounds, sa, sb, indB, indA;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<ll> va(n), vb(n);
        for (int i = 0; i < n; ++i) cin >> va[i];
        for (int i = 0; i < n; ++i) cin >> vb[i];

        sort(va.rbegin(), va.rend());
        sort(vb.rbegin(), vb.rend());

        rounds = n - n / 4;
        sa = 0;
        sb = 0;
        for (int i = 0; i < rounds; ++i) sa += va[i];
        for (int i = 0; i < rounds; ++i) sb += vb[i];
        indA = rounds-1;
        indB = rounds;
        rounds = n;
        while (sb > sa) {
            ++rounds;
            if (rounds % 4) {
                sa += 100;
                if (indB < n) {
                    sb += vb[indB];
                    ++indB;
                }
            }
            else {
                if (indA >= 0 && va[indA] < 100) {
                    sa = sa - va[indA] + 100;
                    --indA;
                }
            }
        }
        cout << rounds - n << '\n';  
    }

    return 0;
}