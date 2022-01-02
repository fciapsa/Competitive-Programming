#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    bool ok = true;
    int n, prev, act;
    cin >> n;
    cin >> prev;
    if (prev > 1) {
        ok = false;
        for (int i = 1; i < prev; ++i) {
            cout << i << '\n';
        }
    }
    --n;
    while (n--) {
        cin >> act;
        if (act != prev + 1) {
            ok = false;
            for (int i = prev + 1; i < act; ++i) {
                cout << i << '\n';
            }
        }
        prev = act;
    }
    if (ok) cout << "good job\n";
    return 0;
}