#include <bits/stdc++.h>

using namespace std;
#define ll long long

int c2i(char c) {
    return int(c) - int('0');
}

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    int i, j, k = 1, n, aux;
    cin >> s;
    while (cin) {
        vector<int> v(s.size());
        v[0] = c2i(s[0]);
        for (int i = 1; i < s.size(); ++i) v[i] = v[i - 1] + c2i(s[i]);

        cin >> n;
        cout << "Case " << k << ":\n";
        while (n--) {
            cin >> i >> j;
            if (i > j) {
                aux = i;
                i = j;
                j = aux;
            }

            if ((s[i] == '0' && v[i] == v[j]) || (s[i] == '1' && v[j] == v[i] + j - i)) cout << "Yes\n";
            else cout << "No\n";
        }
        ++k;
        cin >> s;
    }
    return 0;
}