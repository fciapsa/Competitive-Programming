#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct topic {
    int t, id;
    bool operator<(topic const& other) const {
        return t > other.t;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    int n, neigh, b, ans = 0;
    cin >> n;
    vector<vector<int>> adyList(n);
    vector<int> duration(n);
    vector<int> dependencies(n);

    unordered_set<int> indep;
    for (int i = 0; i < n; ++i) indep.insert(i);

    for (int i = 0; i < n; ++i) {
        cin >> duration[i] >> neigh;
        while (neigh--) {
            cin >> b;
            adyList[i].push_back(b-1);
            indep.erase(b - 1);
            ++dependencies[b - 1];
        }
    }

    priority_queue<topic> pq;
    for (int x : indep) {
        pq.push({ duration[x], x });
    }

    topic act;
    int prev = n - 1;
    while (!pq.empty()) {
        act = pq.top();
        pq.pop();

        ans = max(ans, prev + act.t);
        --prev;

        for (int v : adyList[act.id]) {
            --dependencies[v];
            if (dependencies[v] == 0) pq.push({ duration[v], v });
        }
    }

    cout << ans << '\n';

    return 0;
}