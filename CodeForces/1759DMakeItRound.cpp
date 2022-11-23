#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, twos, fives;
    ll  n, m, aux, multi;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        twos = fives = 0;
        aux = n;
        while (aux % 2 == 0) {
            ++twos;
            aux /= 2;
        }
        aux = n;
        while (aux % 5 == 0) {
            ++fives;
            aux /= 5;
        }

        if (twos > fives) {
            twos -= fives;
            fives = 0;
        }
        else if (fives > twos) {
            fives -= twos;
            twos = 0;
        }
        else twos = fives = 0;

        multi = 1;
        while (twos && multi * 5 <= m) {
            multi *= 5;
            --twos;
        }
        while (fives && multi * 2 <= m) {
            multi *= 2;
            --fives;
        }
        while (multi * 10 <= m) multi *= 10;

        multi *= (m / multi);

        cout << n * multi << '\n';
    }

    return 0;
}