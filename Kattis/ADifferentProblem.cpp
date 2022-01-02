#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    while (cin) {
        cout << abs(a - b) << '\n';
        cin >> a >> b;
    }
return 0;
}