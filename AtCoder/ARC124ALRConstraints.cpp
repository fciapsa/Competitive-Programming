#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <utility>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;
#define ll long long

const ll MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    vector<int> inis(n + 1), fins(n + 1);
    vector<bool> isEndpoint(n + 1, false);
    inis[1] = k;
    fins[n] = k;
    char c;
    int pos;
    for (int i = 0; i < k; ++i) {
        cin >> c >> pos;
        isEndpoint[pos] = true;
        if (c == 'L') {
            --inis[1];
            ++inis[pos];
        }
        else {
            --fins[n];
            ++fins[pos];
        }
    }

    ll sol = 1, opts = 0;
    for (int i = 1; i <= n; ++i) {
        opts += inis[i];
        if(!isEndpoint[i]) sol = (sol * opts) % MOD;
        opts -= fins[i];
    }

    cout << sol << '\n';

    return 0;
}