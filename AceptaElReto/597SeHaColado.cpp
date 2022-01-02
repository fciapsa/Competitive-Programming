#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define ll long long

int main() {
    int k, n, x, sol, min;
    cin >> k;
    while (k--) {
        cin >> n;
        sol = 0;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        min = v[n - 1];
        sol = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (v[i] > min) ++sol;
            else min = v[i];
        }

        cout << sol << '\n';
    }
return 0;
}