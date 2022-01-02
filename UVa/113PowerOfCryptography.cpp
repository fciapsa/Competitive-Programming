#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    double n, p;
    cin >> n >> p;
    while (cin) {
        cout << fixed << setprecision(0) << pow(p, 1 / n) << '\n';
        cin >> n >> p;
    }
    return 0;
}