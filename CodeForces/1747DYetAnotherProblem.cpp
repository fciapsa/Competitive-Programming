#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, q, x, l, r;
    cin >> n >> q;

    vector<ll> v(n + 1), accum(n + 1), pref_xor(n + 1);
    unordered_map<ll, set<ll>> odd_indxs, even_indxs;//<xor value, indexes with such value>
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        accum[i] = accum[i - 1] + v[i];
        pref_xor[i] = (pref_xor[i - 1] ^ v[i]);
        if (i % 2) odd_indxs[pref_xor[i]].insert(i);
        else even_indxs[pref_xor[i]].insert(i);
    }

    while (q--) {
        cin >> l >> r;
        if (accum[l - 1] == accum[r]) cout << "0\n";//all 0
        else if (pref_xor[l - 1] != pref_xor[r]) cout << "-1\n";
        else {//xor of [l,r] is 0
            if ((l - r + 1) % 2 || v[l] == 0 || v[r] == 0) cout << "1\n";//odd length
            else {//check if can split in two parts of odd length
                if (l % 2) {
                    auto it = odd_indxs[pref_xor[l - 1]].lower_bound(l);
                    if (it != odd_indxs[pref_xor[l - 1]].end() && *it < r) cout << "2\n";
                    else cout << "-1\n";
                }
                else {
                    auto it = even_indxs[pref_xor[l - 1]].lower_bound(l);
                    if (it != even_indxs[pref_xor[l - 1]].end() && *it < r) cout << "2\n";
                    else cout << "-1\n";
                }
            }
        }
    }

    
    return 0;
}