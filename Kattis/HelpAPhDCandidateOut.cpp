#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, a, b, i;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        if (s == "P=NP") cout << "skipped\n";
        else {
            i = a = b = 0;
            while (s[i] != '+') {
                a *= 10;
                a += (int(s[i]) - int('0'));
                ++i;
            }
            ++i;
            while (i < s.size()) {
                b *= 10;
                b += (int(s[i]) - int('0'));
                ++i;
            }
            cout << a + b << '\n';
        }
    }
    return 0;
}