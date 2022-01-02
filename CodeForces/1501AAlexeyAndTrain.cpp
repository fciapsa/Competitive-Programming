#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, act, aux;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        vector<int> tm(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
        for (int i = 1; i <= n; ++i) cin >> tm[i];

        act = 0;
        for (int i = 1; i <= n; ++i) {
            act += a[i] - b[i - 1] + tm[i];
            if (i < n) {
                aux = max((int)ceil((b[i] - a[i]) / 2.0), b[i] - act);
                act += aux;
            }
        }

        cout << act << '\n';
    }
    return 0;
}