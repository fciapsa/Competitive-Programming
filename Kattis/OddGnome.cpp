#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, g, prev, act, sol;
    bool b;
    cin >> n;
    while (n--) {
        cin >> g;
        cin >> prev;
        b = true;
        for (int i = 2; i <= g; ++i) {
            cin >> act;
            if (b && act != prev + 1) {
                sol = i;
                b = false;
            }
            prev = act;
        }
        cout << sol << '\n';
    }

    return 0;
}