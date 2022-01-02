#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a;
    while (cin) {
        cin >> b >> c;
        if (a + b + c == 1) {
            if (a == 1) cout << "A\n";
            else if (b == 1)cout << "B\n";
            else cout << "C\n";
        }
        else if (a + b + c == 2) {
            if (a == 0) cout << "A\n";
            else if (b == 0)cout << "B\n";
            else cout << "C\n";
        }
        else cout << "*\n";
        cin >> a;
    }
    return 0;
}