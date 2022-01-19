#include <bits/stdc++.h>

using namespace std;
#define ll long long

int c2i(char c) {
    return int(c) - int('0');
}

int main() {
    std::ios::sync_with_stdio(false);
    int tc, ind, aux, mx;
    string s;
    cin >> tc;
    while (tc--) {
        cin >> s;
        ind = s.size() - 2;
        mx = c2i(s[ind]) + c2i(s[ind + 1]);
        for (int i = s.size()-3; i >= 0 && mx < 10; --i) {
            aux = c2i(s[i]) + c2i(s[i + 1]);
            ind = i;
            mx = max(mx, aux);
        }

        for (int i = 0; i < s.size();) {
            if (i == ind) {
                cout << c2i(s[i]) + c2i(s[i + 1]);
                i += 2;
            }
            else {
                cout << s[i];
                ++i;
            }
        }
        cout << '\n';
    }

    return 0;
}