#include <bits/stdc++.h>

using namespace std;
#define ll long long

void dfs(int u, vector<map<int, int>>& adyList, vector<int>& ts, vector<bool>& vis) {
    vis[u] = true;

    for (auto cv : adyList[u]) {
        if (!vis[cv.first]) {
            dfs(cv.first, adyList, ts, vis);
        }
    }

    ts.push_back(u);
}

int main() {
    std::ios::sync_with_stdio(false);
    int v, e, a, b, c;
    cin >> v >> e;
    while (v|e) {
        vector<map<int,int>> adyList(v);
        vector<set<int>> incide(v);
        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> c;
            --a; --b;
            if (adyList[a].count(b)) adyList[a][b] = max(adyList[a][b], c);
            else adyList[a][b] = c;
            incide[b].insert(a);
        }

        vector<int> ts;
        vector<bool> vis(v, false);
        for (int i = 0; i < v; ++i) {
            if (!vis[i]) {
                dfs(i, adyList, ts, vis);
            }
        }
        reverse(ts.begin(), ts.end());

        vector<int> dp(v);
        vector<int> from(v);
        for (int i = 0; i < v; ++i) from[i] = i;
        for (int i = 0; i < v; ++i) {
            for (int w : incide[ts[i]]) {
                int dist = dp[w] + adyList[w][ts[i]];
                if (dist > dp[ts[i]]) {
                    dp[ts[i]] = dist;
                    from[ts[i]] = w;
                }
                else if (dist == dp[ts[i]]) {
                    vector<int> path1 = { ts[i]};
                    int act = ts[i];
                    while (from[act] != act) {
                        path1.push_back(from[act]);
                        act = from[act];
                    }
                    reverse(path1.begin(), path1.end());

                    vector<int> path2 = { ts[i], w };
                    act = w;
                    while (from[act] != act) {
                        path2.push_back(from[act]);
                        act = from[act];
                    }
                    reverse(path2.begin(), path2.end());

                    bool first_lower = true;
                    for (int j = 0; j < min(path1.size(), path2.size()); ++j) {
                        if (path2[j] > path1[j]) break;
                        if (path2[j] < path1[j]) first_lower = false;
                    }
                    if (!first_lower) from[ts[i]] = w;
                }
            }
        }

        int mx = -1;
        vector<int> path;
        for (int i = 0; i < v; ++i) {
            if (adyList[i].size() == 0) {
                if (dp[i] > mx) {
                    mx = dp[i];
                    path = { i };
                    int act = i;
                    while (from[act] != act) {
                        path.push_back(from[act]);
                        act = from[act];
                    }
                    reverse(path.begin(), path.end());
                }
                else if (dp[i] == mx) {
                    vector<int> curr_path = { i };
                    int act = i;
                    while (from[act] != act) {
                        curr_path.push_back(from[act]);
                        act = from[act];
                    }
                    reverse(curr_path.begin(), curr_path.end());

                    bool lower = false;
                    for (int j = 0; j < min(path.size(), curr_path.size()); ++j) {
                        if (curr_path[j] > path[j]) break;
                        if (curr_path[j] < path[j]) lower = true;
                    }
                    if (lower) path = curr_path;
                }
            }
        }

        cout << mx << '\n';
        cout << ++path[0];
        for (int i = 1; i < path.size(); ++i) cout << ' ' << ++path[i];
        cout << '\n';

        cin >> v >> e;
    }

    return 0;
}

/*int main() {
    std::ios::sync_with_stdio(false);
    int v, e, a, b, c;
    cin >> v >> e;
    while (v|e) {
        vector<vector<pair<int,int>>> adyList(v);
        vector<int> in_deg(v);
        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> c;
            --a;
            --b;
            adyList[b].push_back({ a,c });//reverse graph
            ++in_deg[a];
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> from(v,v+1);
        for (int i = 0; i < v; ++i) {
            if (in_deg[i] == 0) {
                pq.push(i);
                from[i] = i;
            }
        }

        vector<int> dist(v);
        while (!pq.empty()) {//Kahn's topological order
            int act = pq.top();
            pq.pop();

            for (auto par : adyList[act]) {
                --in_deg[par.first];
                if (in_deg[par.first] == 0) pq.push(par.first);

                int d = dist[act] + par.second;
                if (d > dist[par.first]) {
                    dist[par.first] = d;
                    from[par.first] = act;
                }
                else if (d == dist[par.first] && act < from[par.first]) from[par.first] = act;
            }
        }

        int lastV, mx = -1;
        for (int i = 0; i < v; ++i)
            if (dist[i] > mx) {
                mx = dist[i];
                lastV = i;
            }

        vector<int> path = { lastV };
        while (from[lastV] != lastV) {
            path.push_back(from[lastV]);
            lastV = from[lastV];
        }

        cout << mx << '\n';
        cout << ++path[0];
        for (int i = 1; i < path.size(); ++i) cout << ' ' << ++path[i];
        cout << '\n';

        cin >> v >> e;
    }

    return 0;
}*/