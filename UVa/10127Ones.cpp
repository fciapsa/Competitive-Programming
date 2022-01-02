#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, mod, sol;
    cin >> n;
    while (cin) {
        sol = 1;
        mod = 1 % n;
        while (mod) {
            mod = (mod * 10 + 1) % n;
            ++sol;
        }
        cout << sol << '\n';
        cin >> n;
    }
    return 0;
}