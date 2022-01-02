#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, big, small, sol, aux;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        sol = 0;
        for (int i = 1; i < n; ++i) {
            big = max(v[i-1], v[i]);
            small = min(v[i-1], v[i]);
            if (big <= 2 * small) continue;
            aux = small;
            while (big > 2 * aux) {
                ++sol;
                aux *= 2;
            }
        }

        cout << sol << '\n';
    }

return 0;
}