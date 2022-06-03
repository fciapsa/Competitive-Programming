#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    int d1, d2, i, j, k = 1;
    bool ok;
    cin >> s;
    while (s[0] != 'E') {
        if (s.size() == 1) cout << k << " EVEN\n";
        else {
            d1 = 0;
            i = 1;
            while (s[i] != '*') {
                ++d1;
                ++i;
            }

            cout << k << ' ';
            if (i == s.size() - 1) cout << "EVEN\n";
            else {
                ok = true;
                while (i < s.size() - 1 && ok) {
                    j = i + 1;
                    d2 = 0;
                    while (s[j] != '*') {
                        ++j;
                        ++d2;
                    }
                    if (d1 != d2) ok = false;
                    i = j;
                }

                if (ok) cout << "EVEN\n";
                else cout << "NOT EVEN\n";
            }
        }
    ++k;
    cin >> s;
    }

    return 0;
}