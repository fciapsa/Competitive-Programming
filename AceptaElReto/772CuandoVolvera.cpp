#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, r, ini, fin;
    cin >> n >> r;
    while (n) {
        ini = n + 74;
        fin = n + 79;
        for (int i = 2; i <= r; ++i) {
            ini += 74;
            fin += 79;
        }
        cout << "[" << ini << " .. " << fin << "]\n";
        cin >> n >> r;
    }

    return 0;
}