#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ll long long

struct edge {
    int from, to, len, id;
    bool operator<(edge const& o) const {
        return len > o.len;
    }
};

vector<vector<edge>> adyList;
vector<edge> edges;
vector<unordered_set<int>> shortestTraversing;

int p, t;

void dijkstra() {
    shortestTraversing.assign(p, {});
    vector<int> distTo(p, 1e9);
    distTo[0] = 0;
    priority_queue<edge> pq;
    pq.push({ -1,0,0,-1 });

    edge act;
    while (!pq.empty()) {
        act = pq.top();
        pq.pop();

        if (act.len > distTo[act.to]) continue;

        for (auto const& edge : adyList[act.to]) {
            int aux = act.len + edge.len;
            if (aux < distTo[edge.to]) {
                shortestTraversing[edge.to] = { edge.id };
                distTo[edge.to] = aux;
                pq.push({ -1, edge.to, aux, -1 });
            }
            else if (aux == distTo[edge.to]) shortestTraversing[edge.to].insert(edge.id);
        }
    }
}

vector<bool> done;

int floweryTrail(int v) {
    if (done[v]) return 0;
    done[v] = true;

    int ret = 0;
    for (int const& w : shortestTraversing[v]) {
        ret += edges[w].len;
        ret += floweryTrail(edges[w].from);
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> p >> t;
    adyList.assign(p, {});
    int p1, p2, l;
    for(int i = 0; i < t; ++i) {
        cin >> p1 >> p2 >> l;
        adyList[p1].push_back({ p1, p2, l, i});
        adyList[p2].push_back({ p2, p1, l, t+i});
        edges.push_back({ p1, p2, l, i });
    }
    for (int i = 0; i < t; ++i)
        edges.push_back({ edges[i].to, edges[i].from, edges[i].len, edges[i].id });

    dijkstra();
    done.assign(p, false);
    done[0] = true;
    cout << 2*floweryTrail(p-1) << '\n';

    return 0;
}