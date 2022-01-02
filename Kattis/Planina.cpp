#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    vector<ll> pow2(16);
    vector<ll> pow4(16);
    for (int i = 0; i < 16; ++i) {
        pow2[i] = (ll)1 << i;
        pow4[i] = pow2[i] * pow2[i];
    }

    vector<ll> ans(16);
    ans[0] = 4;
    ll added;
    for (int i = 1; i < 16; ++i) {
        added = 5 + 2 * (pow2[i - 1] - 1) * 4 + (pow4[i-1] - (2 * pow2[i - 1] - 1)) * 3;
        ans[i] = ans[i - 1] + added;
    }
    
    int n;
    cin >> n;
    cout << ans[n] << '\n';

    return 0;
}