#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define ll long long
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int tc, n, k, i, j, sol, last, gap;
    string s;
    cin >> tc;
    while (tc--) {
        cin >> n >> k >> s;

        i = 0;
        while (s[i] != '*') ++i;
        j = s.size() - 1;
        while (s[j] != '*') --j;

        if (i != j) sol = 2;
        else sol = 1;

        s[i] = 'x';
        s[j] = 'x';
        
        ++i;
        last = -1;
        gap = 0;
        while (i < j) {
            ++gap;
            if (s[i] == '*') last = i;

            if (gap == k) {
                s[last] = 'x';
                gap = i - last;
                last = -1;
                ++sol;
            }
            ++i;
        }

        cout << sol << '\n';
    }

return 0;
}