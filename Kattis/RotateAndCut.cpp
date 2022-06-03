#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, n, tam, i1, i2, rcs;
    string s;
    cin >> tc;
    while (tc--) {
        cin >> n >> s;
        tam = s.size();
        rcs = 0, i1 = 0, i2 = tam-1;
        while (rcs < n && tam > 3) {
            if (rcs % 2) i2 -= tam / 4;
            else i1 += tam / 4;
            tam = tam - (tam / 4);
            ++rcs;
        }

        for (int i = i1; i <= i2; ++i) cout << s[i];
        cout << '\n';
    }

    return 0;
}