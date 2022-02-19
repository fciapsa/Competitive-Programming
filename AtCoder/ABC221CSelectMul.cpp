#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll s2i(char c) {
    return int(c) - int('0');
}

int main() {
    std::ios::sync_with_stdio(false);
    ll mx = 0, n1, n2, pot;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    do {
        n1 = s2i(s[0]);
        n2 = 0;
        pot = 1;
        for (int i = 1; i < s.size(); ++i) {
            n2 *= 10;
            n2 += s2i(s[i]);
            pot *= 10;
        }
        pot /= 10;

        if (n1 > 0 && n2 > 0 && s[1] != '0') mx = max(n1 * n2, mx);
        for (int i = 1; i < s.size() - 1; ++i) {
            n1 *= 10;
            n1 += s2i(s[i]);
            n2 -= pot * s2i(s[i]);
            pot /= 10;
            if (n1 > 0 && n2 > 0 && s[0] != '0' && s[i+1] != '0') mx = max(n1 * n2, mx);
        }
    } while (std::next_permutation(s.begin(), s.end()));
    
    cout << mx << '\n';

    return 0;
}