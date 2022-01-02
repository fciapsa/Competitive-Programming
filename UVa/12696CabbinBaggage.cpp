#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, ans = 0;
    cin >> n;
    double l, wi, d, we;
    while (n--) {
        cin >> l >> wi >> d >> we;
        if (((l <= 56 && wi <= 45 && d <= 25) || (l + wi + d <= 125)) && we <= 7) {
            ++ans;
            cout << "1\n";
        }
        else cout << "0\n";
    }
    cout << ans << '\n';
    return 0;
}