#include <bits/stdc++.h>

using namespace std;
#define ll long long

int compute(vector<ll> const& v, vector<ll> const& multis, ll h) {
    int res = 0;
    for (int i = 0, j = 0; i < v.size() && (h > v[i] || j < multis.size());) {
        if (h > v[i]) {
            h += (v[i] / 2);
            ++res;
            ++i;
        }
        else {
            h *= multis[j];
            ++j;
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, res, best;
    ll h;
    cin >> tc;
    while (tc--) {
        cin >> n >> h;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.end());

        best = 0;
        best = max(best, compute(v, { 2,2,3 }, h));
        best = max(best, compute(v, { 2,3,2 }, h));
        best = max(best, compute(v, { 3,2,2 }, h));
        cout << best << '\n';
    }

    return 0;
}