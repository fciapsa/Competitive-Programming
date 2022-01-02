#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int shares = 0, x, y;
    double avg = 0;
    string s;
    cin >> s;
    while (s[0] != 'd') {
        if (s[0] == 'b') {
            cin >> x >> y;
            avg = (shares * avg + x * y) / (shares + x);
            shares += x;
        }
        else if (s[0] == 'm') {
            cin >> x;
            shares /= x;
            avg *= x;
        }
        else if (s == "sell") {
            cin >> x >> y;
            shares -= x;
        }
        else {
            cin >> x;
            shares *= x;
            avg /= x;
        }
        cin >> s;
    }
    cin >> y;
    cout << fixed << setprecision(2) << shares * (y - max((y - avg) * 0.3,0.0)) << '\n';

    return 0;
}