#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll n, me;
    cin >> n >> me;
    vector<ll> v(n - 1);
    for (int i = 0; i < n - 1; ++i) cin >> v[i];
    sort(v.rbegin(), v.rend());

    if (v[0] == me) cout << me - v[1] << '\n';
    else {
        vector<ll> diff(n - 1);
        for (int i = 1; i < n - 1; ++i) diff[i] = v[0] - v[i];

        ll ans = 0;
        ll runs = 0;
        ll head = upper_bound(diff.begin(), diff.end(), runs) - diff.begin();
        while (v[0] <= me && head < n-1) {
           ll advance = (ll)floor(log2(head));
           if(advance == 0){//head==1
               ans += v[0] - v[1];
               runs += v[0] - v[1];
           }
           else {
               ll full_cycles = min((me - v[0]) / advance, diff[head] - diff[head - 1]);
               if (full_cycles == 0) {
                   ans += me - v[0];
                   v[0] += advance;
               }
               else {
                   v[0] += advance * full_cycles;
                   ans += (advance + 1) * full_cycles;
                   runs += full_cycles;
               }
           }

           head = upper_bound(diff.begin(), diff.end(), runs) - diff.begin();
        }

        if (v[0] <= me) {//everyone else is head now, it becomes cyclic
            ll advance = (ll)floor(log2(n - 1));
            ll full_cycles = (me - v[0]) / advance;
            v[0] += advance * full_cycles;
            ans += (advance + 1) * full_cycles;
            //this cycle someone catches me
            ans += me - v[0];
        }

        cout << ans << '\n';
    }

    return 0;
}