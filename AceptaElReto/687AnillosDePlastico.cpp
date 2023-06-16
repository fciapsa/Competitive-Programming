#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, cont;
    string s;
    cin >> n;
    while (n) {
        getline(cin, s);
        getline(cin, s);
        cont = 1;
        while (s[0] != '0') {
            ++cont;
            getline(cin, s);
        }
        cout << cont - n << '\n';
        cin >> n;
    }

    return 0;
}