#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, mn = 1e9 + 1, mni, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x < mn) {
            mn = x;
            mni = i;
        }
    }
    cout << mni << '\n';
    return 0;
}