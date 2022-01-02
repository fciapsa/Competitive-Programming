#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        if (a + b == c || a - b == c || b - a == c || a * b == c || (a % b == 0 && a / b == c) || (b % a == 0 && b / a == c))
            cout << "Possible\n";
        else cout << "Impossible\n";
    }
    return 0;
}