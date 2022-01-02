#include <iostream>
#include <vector>
#include <string>

#define ll long long
using namespace std;

int main() {
    ll t, n, x, times, mintimes, tot, aux, k;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        tot = 0;
        mintimes = 100;
        vector<ll> values(n), veces(n);
        for (int i = 0; i < n; ++i) {
            cin >> values[i];
            times = 1;
            aux = values[i];
            while (aux % x == 0) {
                ++times;
                aux /= x;
            }
            veces[i] = times;
            if (times < mintimes) mintimes = times;
        }

        k = 0;
        while (k < n && veces[k] > mintimes) {
            tot += (mintimes + 1) * values[k];
            ++k;
        }
        while (k < n) {
            tot += mintimes * values[k];
            ++k;
        }

        cout << tot << '\n';
    }


return 0;
}