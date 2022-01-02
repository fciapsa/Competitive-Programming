#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll digSum(ll n) {
    ll ans = 0;
    while (n > 0) {
        ans += (n % 10);
        n /= 10;
    }

    return ans;
}

ll love(string s) {
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (isalpha(s[i])) {
            if (islower(s[i])) ans += int(s[i]) - int('a') + 1;
            else ans += int(s[i]) - int('A') + 1;
        }
    }
    while (ans > 9) {
        ans = digSum(ans);
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin,s2);
        double n1 = love(s1);
        double n2 = love(s2);
        if (n1 < n2) cout << fixed << setprecision(2) << n1 / n2 * 100 << " %\n";
        else cout << fixed << setprecision(2) << n2 / n1 * 100 << " %\n";
    }
    return 0;
}