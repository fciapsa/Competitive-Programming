#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    string y, p;
    cin >> y >> p;
    if (y[y.size() - 2] == 'e' && y[y.size() - 1] == 'x') cout << y + p << '\n';
    else if (y[y.size() - 1] == 'e') cout << y + "x" + p << '\n';
    else if (y[y.size() - 1] == 'a' || y[y.size() - 1] == 'i' || y[y.size() - 1] == 'o' ||
        y[y.size() - 1] == 'u') cout << y.substr(0, y.size() - 1) + "ex" + p << '\n';
    else cout << y + "ex" + p << '\n';

    return 0;
}