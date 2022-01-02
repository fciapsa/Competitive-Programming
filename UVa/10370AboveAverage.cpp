#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int tc, above;
    double n, avg;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> v(n);
        avg = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            avg += v[i];
        }
        avg /= n;
        above = 0;
        for (int i = 0; i < n; ++i) if (v[i] > avg) ++above;
        cout << fixed << setprecision(3) << (above / n) * 100 << "%\n";
    }
    return 0;
}