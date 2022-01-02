#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll tc, h, mx_ind, mx, act, peak;
    ll ans;
    string s;
    cin >> tc;
    while (tc--) {
        cin >> s;
        vector<ll> v(s.size()+1);
        v[0] = 0;
        h = 0;
        mx = 0;
        mx_ind = 0;
        for (int i = 1; i <= s.size(); ++i) {
            if (s[i-1] == '/') ++h;
            else if(s[i-1] == '\\') --h;
            v[i] = h;
            if (h > mx) {
                mx = h;
                mx_ind = i;
            }
        }

        ans = 0;
        act = 0;
        while (act < mx_ind) {
            if (v[act] > v[act + 1]) {
                peak = v[act];
                ++act;
                while (v[act] < peak) {
                    ans += peak - v[act];
                    ++act;
                }
            }
            else ++act;
        }

        act = v.size() - 1;
        while (act > mx_ind) {
            if (act > 0 && v[act] > v[act - 1]) {
                peak = v[act];
                --act;
                while (act >= 0 && v[act] < peak) {
                    ans += peak - v[act];
                    --act;
                }
            }
            else --act;
        }

        cout << ans << '\n';
    }
    return 0;
}