#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll to10(string n, ll base) {
    ll sol = 0;
    for (int i = 0; i < n.size(); ++i) {
        sol *= base;
        sol += (int(n[i]) - int('0'));
    }
    return sol;
}

int main() {
    std::ios::sync_with_stdio(false);
    ll k;
    cin >> k;
    string a, b;
    cin >> a >> b;
    cout << to10(a,k) * to10(b,k) << '\n';

    return 0;
}