#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define MAX 1000000

int main() {
    std::ios::sync_with_stdio(false);

    ll t, a, b, ans, pot, digs, aux;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        vector<int> mark(MAX + 1);
        ans = 0;

        pot = 1; digs = 0;
        while (pot <= a) {
            ++digs;
            pot *= 10;
        }
        pot /= 10;

        for(int i = a; i <= b; ++i){
            if (10 * pot == i) {
                ++digs;
                pot *= 10;
            }

            aux = i;
            for (int j = 0; j < digs; ++j) {
                aux = aux / 10 + (aux % 10) * pot;

                if (aux > i && aux <= b) {
                    if (mark[aux] == i) break;
                    mark[aux] = i;
                    ++ans;
                }
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}