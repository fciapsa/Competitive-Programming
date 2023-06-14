#include <bits/stdc++.h>

using namespace std;
#define ll long long

int digs(int x) {
    int ret = 0;
    while (x) {
        ++ret;
        x /= 10;
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, d, ans;
    cin >> n >> d;
    while (n | d) {
        ans = 0;

        int n2 = n, d2 = d;
        while (digs(n2) + digs(d2) < 10) {
            n2 += n;
            d2 += d;

            if (digs(n2) + digs(d2) == 9) {
                set<int> digs;
                int aux1 = n2, aux2 = d2;
                while (aux1) {
                    if (aux1 % 10) digs.insert(aux1 % 10);
                    aux1 /= 10;
                }
                while (aux2) {
                    if (aux2 % 10) digs.insert(aux2 % 10);
                    aux2 /= 10;
                }

                if (digs.size() == 9) ++ans;
            }
        }

        cout << ans << '\n';

        cin >> n >> d;
    }

    return 0;
}