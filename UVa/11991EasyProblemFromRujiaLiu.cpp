#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, k, v, x;
    cin >> n >> m;
    while (cin) {
        //para cada valor, queremos guardar los indices de cada una de sus apariciones
        map<int, vector<int>> mp;

        for (int i = 1; i <= n; ++i) {
            cin >> x;
            mp[x].push_back(i);//el valor x aparece en la posicion i
        }

        //leemos los m queries y los contestamos con coste constante
        for (int i = 0; i < m; ++i) {
            cin >> k >> v;
            if (mp[v].size() < k) cout << "0\n";//no hay al menos k apariciones del valor v
            else cout << mp[v][k - 1] << '\n';//la aparicion 1 en la posicion 0, asi que k-1
        }

    cin >> n >> m;
    }
    return 0;
}