#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct arista {
    int from, to, w;
    bool operator<(arista const& other) const {
        return w < other.w;
    }
};

struct UFDS {
    vector<int> p;
    int numSets;
    UFDS(int n) : p(n, 0), numSets(n) {
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int find(int x) {
        return (p[x] == x) ? x : p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        int i = find(x), j = find(y);
        if (i == j) return;
        p[i] = j;
        --numSets;
    }
};

vector<bool> visited;
vector<vector<arista>> adyList;
map<int,map<int,int>> cj;
int V;

void dfs(int u, vector<arista>& comps) {
    visited[u] = true;
    ++V;

    for (arista e : adyList[u]) {
        if (!visited[e.to]) dfs(e.to, comps);
        int v1 = u, v2 = e.to;
        if (v2 < v1) swap(v1, v2);
        if (cj[v1][v2] == 0) {
            cj[v1][v2] = 1;
            comps.push_back(e);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, u, v, w, selected, cid, ind;
    cin >> n >> m;
    while (n != 0) {
        adyList.assign(n, {});
        while (m--) {
            cin >> u >> v >> w;
            adyList[u].push_back({u, v,w });
            adyList[v].push_back({v, u,w });
        }

        visited.assign(n, false);
        vector<vector<arista>> comps;
        vector<int> heavies;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                comps.push_back({});
                V = 0;
                cj.clear();
                dfs(i, comps[comps.size()-1]);

                cid = comps.size() - 1;
                sort(comps[cid].begin(), comps[cid].end());
                UFDS uf(n);
                selected = 0;
                ind = 0;
                while (selected < V - 1) {
                    if (uf.find(comps[cid][ind].from) != uf.find(comps[cid][ind].to)) {
                        uf.merge(comps[cid][ind].from, comps[cid][ind].to);
                        ++selected;
                    }
                    else heavies.push_back(comps[cid][ind].w);
                    ++ind;
                }
                while (ind < comps[cid].size()) {
                    heavies.push_back(comps[cid][ind].w);
                    ++ind;
                }
            }
        }
        sort(heavies.begin(), heavies.end());
        if (heavies.size() == 0) cout << "forest\n";
        else {
            cout << heavies[0];
            for (int i = 1; i < heavies.size(); ++i) cout << ' ' << heavies[i];
            cout << '\n';
        }

    cin >> n >> m;
    }
    return 0;
}