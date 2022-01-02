#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int a, b, ans;
    cin >> a >> b;
    bool found = false;
    for (int i = 0; i <= 255 && !found; ++i) {
        if ((a ^ i) == b) {
            ans = i;
            found = true;
        }
    }
    cout << ans << '\n';
    return 0;
}