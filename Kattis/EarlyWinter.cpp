#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, k = 0, x;
    bool stop = false;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (!stop && x > m) ++k;
        else stop = true;
    }
    if (k == n) cout << "It had never snowed this early!\n";
    else cout << "It hadn't snowed this early in " << k << " years!\n";
    return 0;
}