#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
    ll t, n, x, ant, act, max, min, tot;
    cin >> t;
    while (t--) {
        cin >> n >> x;

        max = 0;
        tot = 0;
        for (int i = 0; i < n; ++i) {
            cin >> act;
            max += (act / x);
            if (act % x) ++max;
            tot += act;
        }
        min = (tot / x);
        if (tot % x) ++min;

        cout << min << ' ' << max << '\n';
    }

return 0;
}