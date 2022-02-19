#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct sat {
    ll val, cant = 1;
    bool operator<(sat const& other)const {
        return val > other.val;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    ll n, k, avail, ind = 0, sol = 0, veces;
    cin >> n >> k;
    vector<sat> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].val;
    }
    sort(v.begin(), v.end());
    v.push_back({0,0});

    while (k > 0 && ind < v.size() - 1) {
        if (v[ind].val > v[ind + 1].val) {
            avail = v[ind].cant * (v[ind].val - v[ind + 1].val);
            if (avail > k) {
                veces = k / v[ind].cant;
                sol += (v[ind].cant * ((veces * (v[ind].val + v[ind].val - veces + 1)) / 2));
                k -= veces * v[ind].cant;
                sol += k * (v[ind].val - veces);
                k = 0;
            }
            else {
                sol += (v[ind].cant * (((v[ind].val - v[ind + 1].val) * (v[ind].val + v[ind + 1].val + 1)) / 2));
                k -= avail;
            }
        }
        v[ind + 1].cant += v[ind].cant;
        ++ind;
    }

    cout << sol << '\n';

    return 0;
}