#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    int k, m, c, nc, mnc;
    bool ok;
    cin >> k;
    while (k != 0) {
        ok = true;
        cin >> m;
        set<string> conj;
        while (k--) {
            cin >> s;
            conj.insert(s);
        }

        while (m--) {
            cin >> nc >> mnc;
            while (nc--) {
                cin >> s;
                if (conj.count(s)) --mnc;
            }
            if (mnc > 0) ok = false;
        }

        if (ok) cout << "yes\n";
        else cout << "no\n";

        cin >> k;
    }
    return 0;
}