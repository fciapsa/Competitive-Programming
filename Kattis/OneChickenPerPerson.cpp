#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, diff;
    cin >> n >> m;
    if (n > m) {
        diff = n - m;
        cout << "Dr. Chaz needs " << diff << " more piece";
        if (diff > 1) cout << "s";
        cout << " of chicken!\n";
    }
    else {
        diff = m - n;
        cout << "Dr. Chaz will have " << diff << " piece";
        if (diff > 1) cout << "s";
        cout << " of chicken left over!\n";
    }
    return 0;
}