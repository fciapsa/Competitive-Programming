#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long
using namespace std;

struct par {
    ll r, c;
    bool operator<(par const& other)const {
        return r < other.r;
    }
};

int main() {
    std::ios::sync_with_stdio(false);

    ll tc, n, despl, dif;
    ll sol;
    bool has1;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<par> v(n);
        has1 = false;
        for (int i = 0; i < n; ++i) {
            cin >> v[i].r;
            if (v[i].r == 1) has1 = true;
        }
        for (int i = 0; i < n; ++i) cin >> v[i].c;
        if (!has1) v.push_back({ 1,1 });
        sort(v.begin(), v.end());


        sol = 0;
        for (int i = 0; i < v.size()-1; ++i) {
            if ((v[i].r + v[i].c) % 2) {
                despl = v[i + 1].r - v[i].r;
                dif = v[i + 1].c - v[i].c;
                if (despl > dif) {
                    dif = despl - dif;
                    if (dif % 2) sol += (dif/2 + 1);
                    else sol += dif / 2;
                }
            }
            else {
                despl = v[i + 1].r - v[i].r - 1;
                dif = v[i + 1].c - v[i].c;
                if (despl < dif) sol += dif;
                else if (despl > dif) {
                    dif = despl - dif;
                    if (dif % 2) sol += (dif/2+ 1);
                    else sol += dif / 2;
                }
            }
        }

        cout << sol << '\n';

    }
return 0;
}