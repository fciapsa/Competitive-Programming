#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, prev, act, diff, cont;
    cin >> n;
    while (cin) {
        vector<bool> found(n);
        cin >> prev;
        for (int i = 1; i < n; ++i) {
            cin >> act;
            diff = abs(act - prev);
            if (diff < n) found[diff] = true;
            prev = act;
        }
        cont = 0;
        for (int i = 1; i < n; ++i) if (found[i]) ++cont;
        if (cont == n - 1) cout << "Jolly\n";
        else cout << "Not jolly\n";

        cin >> n;
    }
    return 0;
}