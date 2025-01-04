#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    ll prev, act, ans;
    cin >> prev;
    while (prev) {
        ans = prev;
        cin >> act;
        while (act) {
            if (prev + act > ans) ans = prev + act;
            prev = act;
            cin >> act;
        }
        cout << ans << '\n';

        cin >> prev;
    }

    return 0;
}