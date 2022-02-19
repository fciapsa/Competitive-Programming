#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll n, pot = 1, k = 0;
    cin >> n;
    while (pot * 2 <= n) {
        pot *= 2;
        ++k;
    }
    cout << k << '\n';
    return 0;
}