#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string s, s1;
    int cont;
    getline(cin, s);
    while (cin) {
        cont = 0;
        for (int i = 0; i < s.size();) {
            while (i < s.size() && !isalpha(s[i])) ++i;
            if (i < s.size()) {
                ++cont;
                while (i < s.size() && isalpha(s[i])) ++i;
            }
        }

        cout << cont << '\n';
        getline(cin, s);
    }
    return 0;
}