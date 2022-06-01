#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s, p;
    bool ok;
    cin >> s;

    for(int k = 1; k <= s.size(); ++k){
        if (s.size() % k) continue;
        p = s.substr(0, k);
        ok = true;
        for (int i = k; i < s.size() && ok; i += k) {
            p = p[p.size() - 1] + p.substr(0, p.size() - 1);
            for (int j = i; j < i + k && ok; ++j) {
                ok = s[j] == p[j % k];
            }
        }

        if (ok) {
            cout << k << '\n';
            break;
        }
    }

    return 0;
}