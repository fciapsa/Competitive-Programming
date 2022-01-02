#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

int c2i(char c) {
    return int(c) - int('0');
}

int main() {
    std::ios::sync_with_stdio(false);

    int tc;
    string s;
    ll sol, aux, i, prev, shared;
    cin >> tc;
    while (tc--) {
        cin >> s;
        sol = 0;
        i = 0;
        while (i < s.size()) {
            aux = 0;
            shared = 0;
            while (i < s.size() && s[i] == '?') {
                ++aux;
                ++i;
            }
            if (i < s.size()) {
                prev = c2i(s[i]);
                ++aux;
                ++i;
                while (i < s.size() && c2i(s[i]) != prev) {
                    ++aux;
                    if (prev == 0) prev = 1;
                    else prev = 0;
                    ++i;
                }
                if (i < s.size()) {//failed to match
                    while (i - 1 >= 0 && s[i - 1] == '?') {
                        --i;
                        ++shared;
                    }
                }
            }
            sol += (aux * (aux + 1)) / 2;
            sol -= (shared * (shared + 1)) / 2;
        }

        cout << sol << '\n';
    }

return 0;
}