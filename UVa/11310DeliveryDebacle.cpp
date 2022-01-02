#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    vector<ll> v(41);
    v[1] = 1;//n=1 hay 1 forma
    v[2] = 5;//n=2 hay 5 formas
    v[3] = 11;//n=3 hay 11 formas
    for (int i = 4; i < 41; ++i) v[i] = v[i - 1] + 4 * v[i - 2] + 2 * v[i - 3];

    int tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cout << v[n] << '\n';
    }
    return 0;
}