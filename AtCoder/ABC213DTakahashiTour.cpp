#include <bits/stdc++.h>

using namespace std;
#define ll long long

/*
struct par {
    int dest, ind;
    bool operator<(par const& other)const {
        return ind < other.ind;
    }
};
*/

void dfs(int v, vector<set<int>> const& adyList, vector<bool>& marked) {
    if (v == 1) cout << "1";
    else cout << ' ' << v;

    marked[v] = true;

    for (auto it = adyList[v].begin(); it != adyList[v].end(); ++it) {
        if (!marked[*it]) {
            dfs(*it, adyList, marked);
            cout << ' ' << v;
        }
    }

    if (v == 1) cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n;
    vector<set<int>> adyList(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adyList[a].insert(b);
        adyList[b].insert(a);
    }


    vector<bool> marked(n + 1, false);
    dfs(1, adyList, marked);

    return 0;
}