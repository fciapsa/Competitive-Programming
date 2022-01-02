#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, k = 1, tot, h, sol;
    cin >> n;
    while (n != 0) {
        vector<int> v(n);
        tot = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            tot += v[i];
        }
        h = tot / n;
        sol = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] > h) sol += v[i] - h;
        }
        cout << "Set #" << k++ << '\n';
        cout << "The minimum number of moves is " << sol << ".\n\n";
        cin >> n;
    }
    return 0;
}