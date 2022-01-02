#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define ll long long

int main() {
    int n, m, asign, a, b;
    cin >> n >> m;
    while (cin) {
        vector<int> tallas(n), equips(m);
        for (int i = 0; i < n; ++i) cin >> tallas[i];
        for (int i = 0; i < m; ++i) cin >> equips[i];

        sort(tallas.begin(), tallas.end());
        sort(equips.begin(), equips.end());
        asign = 0;
        a = n - 1;
        b = m - 1;
        while (a >= 0 && b >= 0) {
            if (equips[b] == tallas[a] || equips[b] == tallas[a] + 1) {
                ++asign;
                --a;
                --b;
            }
            else if (equips[b] > tallas[a] + 1) --b;
            else --a;
        }

        cout << n - asign << '\n';

    cin >> n >> m;
    }
return 0;
}