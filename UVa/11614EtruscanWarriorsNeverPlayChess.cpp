#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc;
    ll n, ini, fin, m;
    cin >> tc;
    while (tc--) {
        cin >> n;
        n *= 2; //r*(r+1) = 2*n
        ini = 0;
        fin = 2000000000;
        while (fin > ini) {
            if (ini == fin - 1) {
                if (fin * (fin + 1) <= n) ini = fin;
                else fin = ini;
                break;
            }

            m = (ini + fin) / 2;
            if (m * (m + 1) <= n) ini = m;
            else fin = m - 1;
        }

        cout << fin << '\n';
    }
return 0;
}