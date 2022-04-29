#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, x = 0, aux, pot;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        pot = s[s.size() - 1] - '0';
        aux = s[0] - '0';
        for (int i = 1; i < s.size()-1; ++i) {
            aux *= 10;
            aux += s[i] - '0';
        }
        x += pow(aux, pot);
    }
    cout << x << '\n';

    return 0;
}