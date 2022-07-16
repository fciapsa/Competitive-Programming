#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll to_dec(string x) {
    for (int i = 0; i < x.size(); ++i) if (x[i] > '5') --x[i];
    ll num = 0, pot = 1;
    for (int i = x.size() - 1; i >= 0; --i, pot *= 9) {
        num += pot * (int(x[i]) - int('0'));
    }
    return num;
}

int main() {
    std::ios::sync_with_stdio(false);
    ll ad, bd, resd;
    string a, b, res;
    cin >> a >> b;
    while (cin) {
        ad = to_dec(a);
        bd = to_dec(b);
        resd = ad * bd;
        res = "";
        while (resd) {
            res.push_back('0' + (resd % 9));
            resd /= 9;
        }
        if (res == "") res = "0";

        for (int i = 0; i < res.size(); ++i) if (res[i] >= '5') ++res[i];
        reverse(res.begin(), res.end());
        cout << res << '\n';

        cin >> a >> b;
    }

    return 0;
}