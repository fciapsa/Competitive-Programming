#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc;
    ll x, a, b, aux;
    cin >> tc;
    while (tc--) {
        cin >> x;
        a = cbrt((double)x);
        if (a < 1) a = 1;
        b = 1;
        aux = a * a * a + b * b * b;
        while (a >= b && aux != x) {
            if (aux > x && a > 1) --a;
            else ++b;
            aux = a * a * a + b * b * b;
        }
        if (aux == x) cout << "YES\n";
        else cout << "NO\n";
    }

return 0;
}