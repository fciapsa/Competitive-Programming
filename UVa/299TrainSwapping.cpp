#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, l, sol;
    cin >> tc;
    while (tc--) {
        cin >> l;
        vector<int> v(l);
        for (int i = 0; i < l; ++i)cin >> v[i];
        sol = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l - i - 1; ++j) {
                if (v[j] > v[j + 1]) {
                    swap(v[j], v[j + 1]);
                    ++sol;
                }
            }
        }
        cout << "Optimal train swapping takes " << sol << " swaps.\n";
    }
    return 0;
}