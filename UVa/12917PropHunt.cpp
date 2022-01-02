#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int p, h, o;
    cin >> p;
    while (cin) {
        cin >> h >> o;
        if (h > o - p) cout << "Hunters win!\n";
        else cout << "Props win!\n";
        cin >> p;
    }
    return 0;
}