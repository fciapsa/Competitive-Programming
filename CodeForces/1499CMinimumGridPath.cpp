#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    ll tc, n, sol1, aux1, aux2, acum, up, right, sol, minodd, mineven;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];

        acum = v[0] + v[1];
        mineven = v[0];
        minodd = v[1];
        sol = v[0] * n + v[1] * n;
        for (int k = 3; k <= n; ++k) {
            acum += v[k-1];

            if (k % 2 == 0 && v[k-1] < minodd) minodd = v[k-1];
            else if (k % 2 && v[k-1] < mineven) mineven = v[k-1];

            if (k % 2) {
                up = (n - k / 2 - 1) * mineven;
                right = (n - k / 2) * minodd;
                aux1 = up + right + acum;

                up = (n - k / 2) * minodd;
                right = (n - k / 2 - 1) * mineven;
                aux2 = up + right + acum;
            }
            else {
                up = (n - k / 2) * mineven;
                right = (n - k / 2) * minodd;
                aux1 = up + right + acum;

                up = (n - k / 2) * minodd;
                right = (n - k / 2) * mineven;
                aux2 = up + right + acum;
            }
            sol = min(sol, min(aux1, aux2));
        }

        cout << sol << '\n';      
    }

    return 0;
}